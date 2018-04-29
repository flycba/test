// pai.go
package main

import (
	"fmt"
	"math/big"
	"os"
	"time"
)

const prec = 2000000

var a = big.NewFloat(0)
var b = big.NewFloat(0)
var t = big.NewFloat(0)
var p = big.NewFloat(0)

func pai(number int) {
	aa := new(big.Float)
	temp := new(big.Float)

	for number >= int(1) {
		startTime := time.Now()
		number = number - 1
		temp.Add(a, b)
		aa.Quo(temp, big.NewFloat(2))
		temp.Mul(a, b)
		b.Sqrt(temp)
		temp.Sub(a, aa)
		temp.Mul(temp, temp)
		temp.Mul(temp, p)
		t.Sub(t, temp)
		p.Mul(big.NewFloat(2), p)
		a.Copy(aa)
		endTime := time.Now()
		diff := endTime.Sub(startTime)
		fmt.Println(number, "time taken ", diff.Seconds(), "seconds")
	}
}

func suan() {
	pa := new(big.Float).SetPrec(prec).SetInt64(0)
	temp := new(big.Float).SetPrec(prec).SetInt64(0)
	temp1 := new(big.Float).SetPrec(prec).SetInt64(0)

	temp.Add(a, b)
	temp.Mul(temp, temp)
	temp1.Mul(big.NewFloat(4), t)
	pa.Quo(temp, temp1)
	file, _ := os.OpenFile("D:/1.txt", os.O_RDWR|os.O_CREATE, 0666)
	//file.WriteString(fmt.Sprintf("%v", pa))
	a := byte('f')
	file.WriteString(pa.Text(a, 600000))
	file.Close()
}

func main() {

	temp := new(big.Float).SetPrec(prec).SetInt64(0)

	a = new(big.Float).SetPrec(prec).SetInt64(1)
	b = new(big.Float).SetPrec(prec).SetInt64(1)
	p = new(big.Float).SetPrec(prec).SetInt64(1)
	t = new(big.Float).SetPrec(prec).SetInt64(1)

	a = big.NewFloat(1)
	temp.Sqrt(big.NewFloat(2))
	b.Quo(big.NewFloat(1), temp)

	t = big.NewFloat(0.25)
	p = big.NewFloat(1)

	startTime := time.Now()

	pai(19)
	suan()
	endTime := time.Now()
	diff := endTime.Sub(startTime)
	fmt.Println("total time taken ", diff.Seconds(), "seconds")

}
