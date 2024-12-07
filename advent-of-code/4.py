
charGrid: list[list[str]] = []

def create_direction_strings(direction: str) -> list[str]:
  row: int = 0
  col: int = 0
  prev_row: int = 0
  prev_col: int = 0

  match(direction):
    case "right":
      row = 0
      col = 0
    case "down":
      row = 0
      col = 0
    case "right_down_diagonal":
      row = len(charGrid)-1
      col = 0
      prev_row = len(charGrid)-1
      prev_col = 0
    case "right_up_diagonal":
      row = 0
      col = 0
      prev_row = 0
      prev_col = 0

  count_checked: int = 0;
  res: list[str] = [""]

  while count_checked < len(charGrid) * len(charGrid[0]):
    res[-1] += charGrid[row][col]
    match(direction):
      case "right":
        if col == len(charGrid[0])-1:
          col = 0
          row += 1
          res.append("")
        else:
          col += 1
      case "down":
        if row == len(charGrid)-1:
          row = 0
          col += 1
          res.append("")
        else:
          row += 1
      case "right_down_diagonal":
        if col == len(charGrid[0])-1:
          row = 0
          col = prev_col + 1
          prev_col = col
          res.append("")
        elif row == len(charGrid)-1:
          row = prev_row - 1
          prev_row = row
          col = 0
          res.append("")
        else:
          col += 1
          row += 1
      case "right_up_diagonal":
        if col == len(charGrid[0])-1:
          row = len(charGrid)-1
          col = prev_col + 1
          prev_col = col
          res.append("")
        elif row == 0:
          row = prev_row + 1
          prev_row = row
          col = 0
          res.append("")
        else:
          col += 1
          row -= 1
    count_checked += 1
  return res

def count_x_mas() -> int:
  rows = len(charGrid)
  cols = len(charGrid[0])
  count = 0

  def is_mas(s: str) -> bool:
    return s in ["MAS", "SAM"]

  for r in range(1, rows-1):
    for c in range(1, cols-1):
      diagonal1 = charGrid[r-1][c-1] + charGrid[r][c] + charGrid[r+1][c+1]
      diagonal2 = charGrid[r-1][c+1] + charGrid[r][c] + charGrid[r+1][c-1]

      if is_mas(diagonal1) and is_mas(diagonal2):
        count += 1
  return count

def main():
  with open("4.txt", "r") as file:
    for line in file:
      charGrid.append(list(line)[:-1])

  right: list[str] = create_direction_strings("right")
  down: list[str] = create_direction_strings("down")
  right_down_diagonal: list[str] = create_direction_strings("right_down_diagonal")
  right_up_diagonal: list[str] = create_direction_strings("right_up_diagonal")

  sum: int = 0
  for line in right: sum += line.count("XMAS")
  for line in right: sum += line.count("SAMX")
  for line in down: sum += line.count("XMAS")
  for line in down: sum += line.count("SAMX")
  for line in right_down_diagonal: sum += line.count("XMAS")
  for line in right_down_diagonal: sum += line.count("SAMX")
  for line in right_up_diagonal: sum += line.count("XMAS")
  for line in right_up_diagonal: sum += line.count("SAMX")

  print(sum)

  #.....there is a muuuuch easier way to do this.....

  print(count_x_mas())

if __name__ == "__main__":
  main()
