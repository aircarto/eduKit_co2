# eduKit CO2

Projet pour Raspberry Pi Pico 2 W avec PlatformIO.

## Prérequis

- [VS Code](https://code.visualstudio.com/)
- Extension [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

## Matériel

- Raspberry Pi Pico 2 W
- Écran OLED I2C 128x64 (SSD1306)

## Câblage

### Écran OLED I2C

| OLED | Pico 2 W | GPIO |
|------|----------|------|
| VCC  | 3V3 (pin 36) | - |
| GND  | GND (pin 38) | - |
| SDA  | Pin 6 | GP4 |
| SCL  | Pin 7 | GP5 |

```
        Pico 2 W
    ┌───────────────┐
    │ [USB]         │
    │               │
    │ GP4 (6)  ───────── SDA (OLED)
    │ GP5 (7)  ───────── SCL (OLED)
    │               │
    │ 3V3 (36) ───────── VCC (OLED)
    │ GND (38) ───────── GND (OLED)
    │               │
    └───────────────┘
```

## Structure du projet

```
├── platformio.ini    # Configuration PlatformIO
├── src/
│   └── main.cpp      # Code principal
└── README.md
```

## Upload sur le Pico

### Première fois (mode BOOTSEL)

1. Déconnecte le Pico de l'USB
2. Maintiens le bouton **BOOTSEL** enfoncé
3. Connecte le Pico à l'USB tout en maintenant BOOTSEL
4. Relâche le bouton (le Pico apparaît comme un lecteur USB)
5. Dans VS Code, clique sur **Upload** (flèche →) dans la barre PlatformIO en bas

### Uploads suivants

Une fois le premier upload effectué :

1. Clique sur **Upload** dans la barre PlatformIO
2. Ou utilise le raccourci `Ctrl+Alt+U`
3. Ou dans le terminal : `pio run -t upload`

## Commandes PlatformIO utiles

| Commande | Description |
|----------|-------------|
| `pio run` | Compile le projet |
| `pio run -t upload` | Compile et upload |
| `pio run -t clean` | Nettoie les fichiers de build |
| `pio device monitor` | Moniteur série (115200 baud) |
