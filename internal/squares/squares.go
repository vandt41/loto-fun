package squares

type Square struct {
	IsEmpty bool
	Number  int
}

func NewSquare() *Square {
	return &Square{
		IsEmpty: true,
		Number:  0,
	}
}
