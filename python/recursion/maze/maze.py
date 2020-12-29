def find_maze(start_row, start_col, row_len, col_len, maze):
    
    def _find_maze(current_row, current_col, current_maze):
        '''
        * Method of implementation
        - check the values in east, west, north, south value from current position,
            - find exit
                - return a position of exit
            - not find exit
                - repeat moveing to next position
                - condier a wall and passed way
    
        * Reason for 3rd parameter (current_maze)
        - each recursion function has its passed way.
        - so in order to backtrack each function, it needs current_maze parameter.
        '''
        current_maze[current_row][current_col] = 3  # flag of passed way for backtracking

        # check south way
        if current_row+1 < row_len:  # check row length of an array
            if maze[current_row+1][current_col] == 2:  # check if it is end
                return current_row+1, current_col
            elif maze[current_row+1][current_col] == 0 and maze[current_row+1][current_col] != 3:  # check if is the way and is not passed way
                result_row, result_col = _find_maze(current_row+1, current_col, current_maze)  # move to south
                if result_row is not None and result_col is not None:
                    return result_row, result_col

        # check east way
        if current_col+1 < col_len:
            if maze[current_row][current_col+1] == 2:
                return current_row, current_col+1
            elif maze[current_row][current_col+1] == 0 and maze[current_row][current_col+1] != 3:
                result_row, result_col = _find_maze(current_row, current_col+1, current_maze)
                if result_row is not None and result_col is not None:
                    return result_row, result_col

        # check north way
        if current_row-1 >= 0:
            if maze[current_row-1][current_col] == 2:
                return current_row-1, current_col
            elif maze[current_row-1][current_col] == 0 and maze[current_row-1][current_col] != 3:
                result_row, result_col = _find_maze(current_row-1, current_col, current_maze)
                if result_row is not None and result_col is not None:
                    return result_row, result_col

        # check west way
        if current_col-1 >= 0:
            if maze[current_row][current_col-1] == 2:
                return current_row, current_col-1
            elif maze[current_row][current_col-1] == 0 and maze[current_row][current_col-1] != 3:
                result_row, result_col = _find_maze(current_row, current_col-1, current_maze)
                if result_row is not None and result_col is not None:
                    return result_row, result_col

        return None, None  # blocked way or no end found

    return _find_maze(start_row, start_col, maze)


def main():
    row_len = None
    col_len = None
    maze = list()
    start_row = None
    start_col = None

    with open('input', 'r') as fd:
        first_line = fd.readline().split(' ')
        row_len, col_len = int(first_line[0]), int(first_line[1])

        for _ in range(0, row_len):
            maze.append([int(row) for row in fd.readline().split(' ')])

        end_line = fd.readline().split(' ')
        start_row, start_col = int(end_line[0]), int(end_line[1])
    
    end_row, end_col = find_maze(start_row, start_col, row_len, col_len, maze)
    print(end_row, end_col)

if __name__ == '__main__':
    main()
