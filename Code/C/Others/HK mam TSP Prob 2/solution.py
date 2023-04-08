import random
import math

POP_NO = 90      # number of bats
DIM = 10         # number of dimensions
ITERATIONS = 100 # number of iterations

class Bat:
    def __init__(self):
        self.pos = [0] * DIM
        self.pulse = 0
        self.vel = [0] * DIM
        self.loud = 0
        self.freq = 0
        self.fit = 0

def initiate(bats):
    for bat in bats:
        for j in range(DIM):
            bat.pos[j] = random.uniform(0, 2)
            bat.vel[j] = random.random()
        bat.pulse = random.uniform(0, 1)
        bat.loud = random.uniform(1, 2)
        bat.freq = random.uniform(0, 2)

def calculate_fitness(bats):
    for bat in bats:
        bat.fit = sum([pos**2 for pos in bat.pos])

def best_fitness(bats):
    return min(range(len(bats)), key=lambda i: bats[i].fit)

def adjust_freq(bats, new_bats):
    for i in range(POP_NO):
        new_bats[i].freq = random.uniform(0, 2)

def update_velocity(bats, new_bats, index):
    for bat, new_bat in zip(bats, new_bats):
        new_bat.vel = [
            vel + (pos - bats[index].pos[j]) * bat.freq
            for j, (vel, pos) in enumerate(zip(bat.vel, bat.pos))
        ]

def update_position(bats, new_bats):
    for bat, new_bat in zip(bats, new_bats):
        new_bat.pos = [pos + vel for pos, vel in zip(bat.pos, bat.vel)]

def generate_local_solution(bats, index):
    avg_loud = sum([bat.loud for bat in bats]) / POP_NO
    eta = random.uniform(-1, 1)

    for j in range(DIM):
        bats[index].pos[j] += eta * avg_loud
        bats[index].pos[j] = min(max(bats[index].pos[j], 0), 2)

def update_loud_pulse(bats):
    alpha = 0.5
    t = 1
    gamma = 0.9

    for bat in bats:
        bat.loud *= alpha
        r0 = bat.pulse * 0.001 / 100
        bat.pulse = r0 * (1 - math.exp(-gamma * t))

def main():
    bats = [Bat() for _ in range(POP_NO)]
    random.seed()
    A = random.random()

    itr = 0
    best_gen = 0

    initiate(bats)
    calculate_fitness(bats)

    best_idx = best_fitness(bats)
    global_best_fit = bats[best_idx].fit

    while itr < ITERATIONS:
        new_bats = [Bat() for _ in range(POP_NO)]
        print(f"Gen: {itr + 1} and Best Fitness {bats[best_idx].fit:.4f}")

        adjust_freq(bats, new_bats)
        update_velocity(bats, new_bats, best_idx)
        update_position(bats, new_bats)

        calculate_fitness(new_bats)

        for i in range(POP_NO):
            if bats[i].pulse > random.random():
                generate_local_solution(bats, i)

            if random.random() < bats[i].loud and new_bats[i].fit < bats[i].fit:
                update_loud_pulse(bats)

        calculate_fitness(new_bats)

        for i in range(POP_NO):
            if new_bats[i].fit < bats[i].fit:
                bats[i].fit = new_bats[i].fit
                bats[i].freq = new_bats[i].freq
                for j in range(DIM):
                    bats[i].pos[j] = new_bats[i].pos[j]
                    bats[i].vel[j] = new_bats[i].vel[j]

        best_idx = best_fitness(bats)

        if bats[best_idx].fit < global_best_fit:
            global_best_fit = bats[best_idx].fit
            best_gen = itr

        itr += 1

    print(f"Best fit was found at {best_gen + 1} Iteration with {global_best_fit:.4f} Fitness")

if __name__ == "__main__":
    main()
