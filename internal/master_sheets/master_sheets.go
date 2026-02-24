package master_sheets

import (
    "fmt"

    "loto/internal/squares"
    "loto/internal/colors"
)

type MasterSheet struct {
    Numbers [18][9]squares.Square
    Color   colors.Color        
}

func NewMasterSheet(color colors.Color) *MasterSheet { 
    masterSheet := &MasterSheet{
        Color: color,
    }

    for row := 0; row < 18; row++ {
        for col := 0; col < 9; col++ {
            masterSheet.Numbers[row][col] = *squares.NewSquare()  
        }
    }
    return masterSheet
}

func (ms *MasterSheet) DisplayGrid() {
    fmt.Println("- Numbers: ")
    fmt.Println("- Sheet 1: ")
    for i := 0; i < len(ms.Numbers); i++ {
        for j := 0; j < len(ms.Numbers[i]); j++ {
            if i == 9 && j == 0 {
                fmt.Println("- Sheet 2: ")
            }
            if ms.Numbers[i][j].IsEmpty {
                fmt.Printf(" # ")  
            } else {
                fmt.Printf("%2d ", ms.Numbers[i][j].Number)  
            }
        }
        fmt.Println()
    }
}

func (ms *MasterSheet) Display() {
    fmt.Println("You card is: ")
    fmt.Printf("- Color: %s\n", ms.Color.String()) 
    ms.DisplayGrid()
}

// func (ms *MasterSheet) Generate() {
//     rand.Seed(time.Now().UnixNano())
//
//     columnRanges := [9][2]int{
//         {1, 9},     
//         {10, 19},   
//         {20, 29},   
//         {30, 39},   
//         {40, 49},   
//         {50, 59},   
//         {60, 69},   
//         {70, 79},   
//         {80, 90},   
//     }
// } 
