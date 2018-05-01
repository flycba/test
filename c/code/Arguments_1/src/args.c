#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <sys/inotify.h>  
#include <unistd.h>  

#define EVENT_NUM 12  

char *event_str[EVENT_NUM] = {
  "IN_ACCESS",
  "IN_MODIFY",
  "IN_ATTRIB",
  "IN_CLOSE_WRITE",
  "IN_CLOSE_NOWRITE",
  "IN_OPEN",
  "IN_MOVED_FROM",
  "IN_MOVED_TO",
  "IN_CREATE",
  "IN_DELETE",
  "IN_DELETE_SELF",
  "IN_MOVE_SELF"
};

int
main (int argc, char *argv[])
{
  int fd1;
  int fd2;
  int fd3;
  int wd1;
  int wd2;
  int wd3;
  int len;
  int nread;
  char buf[BUFSIZ];
  struct inotify_event *event;
  int i;

  char *a = "/home/flycba/mygo/bin";
  char *b = "/home/flycba/mygo/pkg";
  char *c = "/home/flycba/mygo/src";

  fd1 = inotify_init ();
  fd2 = inotify_init ();
  fd3 = inotify_init ();
  if (fd1 < 0)
    {
      fprintf (stderr, "1 inotify_init failed\n");
      return -1;
    }
  if (fd2 < 0)
    {
      fprintf (stderr, "2 inotify_init failed\n");
      return -1;
    }
  if (fd3 < 0)
    {
      fprintf (stderr, "3 inotify_init failed\n");
      return -1;
    }
  wd1 = inotify_add_watch (fd1, a, IN_CREATE);
  if (wd1 < 0)
    {
      fprintf (stderr, "inotify_add_watch %s failed\n", a);
      return -1;
    }

  wd2 = inotify_add_watch (fd2, b, IN_CREATE);
  if (wd2 < 0)
    {
      fprintf (stderr, "inotify_add_watch %s failed\n", a);
      return -1;
    }

  wd3 = inotify_add_watch (fd3, c, IN_CREATE);
  if (wd3 < 0)
    {
      fprintf (stderr, "inotify_add_watch %s failed\n", a);
      return -1;
    }

  buf[sizeof (buf) - 1] = 0;
  while ((len = read (fd1, buf, sizeof (buf) - 1)) > 0)
    {
      nread = 0;
      while (len > 0)
        {
          event = (struct inotify_event *) &buf[nread];
          for (i = 0; i < EVENT_NUM; i++)
            {
              if ((event->mask >> i) & 1)
                {
                  if (event->len > 0)
                    fprintf (stdout, "%s --- %s\n", event->name, event_str[i]);
                  else
                    fprintf (stdout, "%s --- %s\n", " ", event_str[i]);
                }
            }
          nread = nread + sizeof (struct inotify_event) +event->len;
          len = len - sizeof (struct inotify_event) -event->len;
        }
    }

  return 0;
}
