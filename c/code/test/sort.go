// sort
package main

import (
	"container/heap"
	"fmt"
	"sort"
)

//
type Student struct {
	name   string
	fenshu int
}

type Stus []Student

func (s Stus) Len() int {
	return len(s)
}

func (s Stus) Less(i, j int) bool {
	return s[i].fenshu < s[j].fenshu
}

func (s Stus) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s *Stus) Push(x interface{}) {
	*s = append(*s, x.(Student))
}

func (s *Stus) Pop() interface{} {
	old := *s
	n := s.Len()
	x := old[n-1]
	*s = old[0 : n-1]
	return x
}

func main() {
	stus := Stus{
		{"AA", 40},
		{"BB", 20},
		{"CC", 50},
	}
	for _, v := range stus {
		fmt.Println(v.name, "::", v.fenshu)
	}
	sort.Sort(stus)
	for _, v := range stus {
		fmt.Println(v.name, "::", v.fenshu)
	}
	fmt.Println("stus::Len:", stus.Len())
	s := &stus
	heap.Init(s)
	heap.Push(s, Student{"DD", 60})

	heap.Push(s, Student{"FF", 77})

	for _, v := range stus {
		fmt.Println(v.name, ":::", v.fenshu)
	}
	heap.Pop(s)

	for _, v := range stus {
		fmt.Println(v.name, " : ", v.fenshu)
	}
}
