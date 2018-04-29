// e.go
package main

import (
	"fmt"
	"math/big"
	//"os"
	"time"
)

const prec = 2000000

func sue(number int64) *big.Int {
	aa := big.NewInt(1)
	if number == 0 {
		return aa
	}

	for number > 0 {
		temp := big.NewInt(number)
		aa.Mul(aa, temp)
		//fmt.Printf("n! %v\n", aa)
		number--
	}
	return aa
}

func main() {

	//temp := new(big.Float).SetPrec(prec).SetInt64(0)

	a := big.NewInt(1)
	//b := big.NewFloat(0)
	//e := big.NewFloat(1)
	b := new(big.Float).SetPrec(prec).SetInt64(1)
	e := new(big.Float).SetPrec(prec).SetInt64(1)

	number := int64(500)
	startTime := time.Now()

	for number > 0 {
		a = sue(number)
		b.SetInt(a)
		b.Quo(big.NewFloat(1), b)
		e.Add(e, b)
		fmt.Printf("n! %v 1/n! %v e:%v\n", a, b, e)
		number--
	}
	endTime := time.Now()
	diff := endTime.Sub(startTime)
	fmt.Printf("n! %v 1/n! %v e:%v\n", a, b, e)
	fmt.Println("total time taken ", diff.Seconds(), "seconds")
}
