import pygame
import random

# Initialize pygame
pygame.init()

# Set up the game window
WINDOW_WIDTH = 600
WINDOW_HEIGHT = 600
game_window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
pygame.display.set_caption("Snake Game")

# Define the colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# Define the block size and speed of the snake
BLOCK_SIZE = 10
SPEED = 15

# Define the font for the score display
font = pygame.font.SysFont(None, 30)

# Define the function to display the score
def display_score(score):
    score_text = font.render("Score: " + str(score), True, WHITE)
    game_window.blit(score_text, [10, 10])


# Define the main game loop
def game_loop():
    # Initialize the snake
    snake_pos = [300, 300]
    snake_body = [[300, 300], [290, 300], [280, 300]]
    snake_direction = "RIGHT"
    snake_change = BLOCK_SIZE

    # Initialize the food
    food_pos = [
        random.randrange(1, (WINDOW_WIDTH // BLOCK_SIZE)) * BLOCK_SIZE,
        random.randrange(1, (WINDOW_HEIGHT // BLOCK_SIZE)) * BLOCK_SIZE,
    ]

    # Initialize the score
    score = 0

    # Run the game loop
    game_over = False
    while not game_over:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT and snake_direction != "RIGHT":
                    snake_direction = "LEFT"
                    snake_change = -BLOCK_SIZE
                elif event.key == pygame.K_RIGHT and snake_direction != "LEFT":
                    snake_direction = "RIGHT"
                    snake_change = BLOCK_SIZE
                elif event.key == pygame.K_UP and snake_direction != "DOWN":
                    snake_direction = "UP"
                    snake_change = -BLOCK_SIZE
                elif event.key == pygame.K_DOWN and snake_direction != "UP":
                    snake_direction = "DOWN"
                    snake_change = BLOCK_SIZE

        # Move the snake
        snake_pos[0] += snake_change
        snake_body.insert(0, list(snake_pos))
        if snake_pos[0] == food_pos[0] and snake_pos[1] == food_pos[1]:
            food_pos = [
                random.randrange(1, (WINDOW_WIDTH // BLOCK_SIZE)) * BLOCK_SIZE,
                random.randrange(1, (WINDOW_HEIGHT // BLOCK_SIZE)) * BLOCK_SIZE,
            ]
            score += 10
        else:
            snake_body.pop()

        # Check for game over conditions
        if (
            snake_pos[0] < 0
            or snake_pos[0] > WINDOW_WIDTH - BLOCK_SIZE
            or snake_pos[1] < 0
            or snake_pos[1] > WINDOW_HEIGHT - BLOCK_SIZE
            or snake_pos in snake_body[1:]
        ):
            game_over = True

        # Update the game window
        game_window.fill(BLACK)
        for pos in snake_body:
            pygame.draw.rect(
                game_window, GREEN, [pos[0], pos[1], BLOCK_SIZE, BLOCK_SIZE]
            )
        pygame.draw.rect(
            game_window, RED, [food_pos[0], food_pos[1], BLOCK_SIZE, BLOCK_SIZE]
        )
        display_score(score)
        pygame.display.update()

        # Set the game speed
        pygame.time.delay(SPEED)

        # Quit pygame and exit the program
        pygame.quit()
        quit()


# Call the main game loop
game_loop()


# This implementation uses the arrow keys to control the movement of the snake, and the goal is to eat as much food as possible without running into the walls or the snake's own body. The score is displayed in the top left corner of the game window.
