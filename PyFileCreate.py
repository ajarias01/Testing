import json

class SoundMixer:
    def __init__(self, mixer_id, brand, channels, price):
        self.id = mixer_id
        self.brand = brand
        self.channels = channels
        self.price = price
    
    def to_dict(self):
        return {
            'id': self.id,
            'brand': self.brand,
            'channels': self.channels,
            'price': self.price
        }

def save_to_json(mixers):
    mixer_list = [mixer.to_dict() for mixer in mixers]
    with open('sound_mixers.json', 'w') as f:
        json.dump(mixer_list, f, indent=4)

def load_from_json():
    try:
        with open('sound_mixers.json', 'r') as f:
            mixer_list = json.load(f)
            mixers = [SoundMixer(mixer['id'], mixer['brand'], mixer['channels'], mixer['price']) for mixer in mixer_list]
    except FileNotFoundError:
        mixers = []
    
    return mixers

def add_sound_mixer():
    mixer_id = input("Enter ID: ")
    brand = input("Enter brand: ")
    channels = int(input("Enter number of channels: "))
    price = float(input("Enter price: "))
    
    mixer = SoundMixer(mixer_id, brand, channels, price)
    mixers.append(mixer)
    save_to_json(mixers)
    print(f"Sound Mixer with ID {mixer_id} added successfully.")

mixers = load_from_json()

if __name__ == "__main__":
    while True:
        print("\nMenu:")
        print("1. Add Sound Mixer")
        print("2. Exit")
        
        choice = input("Enter your choice: ")
        
        if choice == '1':
            add_sound_mixer()
        elif choice == '2':
            break
        else:
            print("Invalid choice. Please enter 1 or 2.")
