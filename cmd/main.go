package main

import (
    "loto/internal/colors"
    ms "loto/internal/master_sheets"
)

func main() {
    ms := ms.NewMasterSheet(colors.Red)
    ms.Display()
}
