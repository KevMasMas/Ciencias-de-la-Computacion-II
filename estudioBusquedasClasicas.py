slots = 10

hash_table = []

def init():
    for i in range(slots):
        hash_table.append([])

def hashTableModule(key: int):
    return key % slots

def insert(key: int):
    slot = hashTableModule(key)
    inicio = slot

    while len(hash_table[slot]) >= 2:
        print(f"Colisión en el cubo {slot}")
        slot = (slot + 1) % slots  # Pasa al siguiente cubo

        if slot == inicio:
            print("La tabla está llena")
            return

    hash_table[slot].append(key)

init()

insert(15)
insert(22)
insert(42)
insert(45)
insert(11)
insert(52)
insert(62)

print(hash_table)