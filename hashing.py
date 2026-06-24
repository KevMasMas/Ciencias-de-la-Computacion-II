slots: int = 10

hash_table = []

def init():
    for i in range(slots):
        hash_table.append([])

def hash_function_module(key: int) -> int:
    return key % slots

def hash_function_midsquare(key: int) -> str:
    remove_ = 1
    slot = str(key ** 2)
    slot = slot[remove_:-remove_]
    return slot

def hash_function_truncate(key: int) -> str:
    positions = (3, 4, 8)
    key_str = str(key)
    slot = ''
    for p in positions:
        slot += key_str[p]
    return slot

def insert(key: int):
    slot = hash_function_module(key)
    if slot not in hash_table:
        hash_table[slot] = []
    hash_table[slot].append(key)

def search(key: int) -> int:
    slot = hash_function_module(key)
    value = -1
    for i, key_i in enumerate(hash_table[slot]): #Aca busca el indice de en que parte esta del slot ( en que parte esta de la lista de la lista)
        if key_i == key:
            value = slot, i  #Python deja guardar dupla para devolver
    return value


init()
insert(45052)
print(search(45052))