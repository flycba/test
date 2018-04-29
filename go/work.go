package main

import (
	"fmt"
	//	"math/rand"
	"sync"
	"time"
)

type Job struct {
	id       int64
	randomno int64
}
type Result struct {
	job         Job
	sumofdigits int64
}

var jobs = make(chan Job, 100)
var results = make(chan Result, 100)

func digits(number int64) int64 {
	a := float64(1.00000000000000000000000000000000000000000000000001)
	for number < int64(10) {
		number--
		a = a * a
	}
	//time.Sleep(2 * time.Second)
	return number * int64(a)
}
func worker(wg *sync.WaitGroup) {
	for job := range jobs {
		output := Result{job, digits(job.randomno)}
		results <- output
	}
	wg.Done()
}
func createWorkerPool(noOfWorkers int64) {
	var wg sync.WaitGroup
	for i := int64(0); i < noOfWorkers; i++ {
		wg.Add(1)
		go worker(&wg)
	}
	wg.Wait()
	close(results)
}
func allocate(noOfJobs int64) {
	for i := int64(0); i < noOfJobs; i++ {
		//randomno := rand.Intn(100000)
		randomno := int64(599999999999999990)
		job := Job{i, randomno}
		jobs <- job
	}
	close(jobs)
}
func result(done chan bool) {
	for result := range results {
		result.sumofdigits, result.job.randomno = result.job.randomno, result.sumofdigits
		//t.Printf("Job id %d, input random no %d , sum of digits %d\n", result.job.id, result.job.randomno, result.sumofdigits)
	}
	done <- true
}
func main() {
	startTime := time.Now()
	noOfJobs := int64(20000000)
	go allocate(noOfJobs)
	done := make(chan bool)
	go result(done)
	noOfWorkers := int64(1)
	createWorkerPool(noOfWorkers)
	<-done
	endTime := time.Now()
	diff := endTime.Sub(startTime)
	fmt.Println("total time taken ", diff.Seconds(), "seconds")
}
