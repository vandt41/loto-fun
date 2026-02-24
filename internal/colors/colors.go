package colors

type Color int

const (
    Red Color = iota
    Blue
    Green
    Yellow
    Purple
    Pink
)

func (c Color) String() string {
    switch c {
    case Red:
        return "red"
    case Blue:
        return "blue"
    case Green:
        return "green"
    case Yellow:
        return "yellow"
    case Purple:
        return "purple"
    case Pink:
        return "pink"
    default:
        return "unknown"
    }
}
