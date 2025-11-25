# Tic Tac Toe in Python

b = ['1','2','3','4','5','6','7','8','9']
player = 'X'


def showBoard():
    for i in range(9):
        print(b[i], end=' ')
        if (i + 1) % 3 == 0:
            print()
            

def move():
    global player
    while True:
        try:
            m = int(input(f"Player {player}'s turn, enter move (1-9): "))
        except ValueError:
            print("Invalid input! Enter a number from 1-9.")
            continue

        if m < 1 or m > 9:
            print("Invalid move! Position out of range. Try again.")
        elif b[m - 1] in ['X', 'O']:
            print("Invalid move! Position already taken. Try again.")
        else:
            b[m - 1] = player
            break


def win():
    return (
        (b[0] == b[1] == b[2]) or
        (b[3] == b[4] == b[5]) or
        (b[6] == b[7] == b[8]) or
        (b[0] == b[3] == b[6]) or
        (b[1] == b[4] == b[7]) or
        (b[2] == b[5] == b[8]) or
        (b[0] == b[4] == b[8]) or
        (b[2] == b[4] == b[6])
    )


def draw():
    return all(c in ['X', 'O'] for c in b)


def switch_player():
    global player
    player = 'O' if player == 'X' else 'X'


def game():
    global player
    while True:
        showBoard()
        move()

        if win():
            showBoard()
            print(f"Player {player} won!")
            break
        
        if draw():
            showBoard()
            print("It's a draw!")
            break
        
        switch_player()


if __name__ == "__main__":
    game()
