package roles

type Role int

const (
    Host Role = iota
    Player
)

func (r Role) String() string {
    switch r {
    case Host:
        return "host"
    case Player:
        return "player"
    default:
        return "unknown"
    }
}
