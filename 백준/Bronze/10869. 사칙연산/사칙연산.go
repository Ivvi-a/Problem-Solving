package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader *bufio.Reader = bufio.NewReader(os.Stdin)
	writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

func main() {
	defer writer.Flush()
	var a, b int
	fmt.Fscanln(reader, &a, &b)
	fmt.Fprintln(writer, a+b)
	fmt.Fprintln(writer, a-b)
	fmt.Fprintln(writer, a*b)
	fmt.Fprintln(writer, a/b)
	fmt.Fprintln(writer, a%b)
}