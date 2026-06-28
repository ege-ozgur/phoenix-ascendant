# Phoenix Ascendant

**Phoenix Ascendant** is a third-person action game developed in **Unreal Engine 5.4.4** using a hybrid **C++ and Blueprint** architecture. The player controls Phoenix and switches between fire and light attacks to exploit enemy weaknesses, survive enemy waves, activate ancient altars, and restore the ruined crypt.

## Submission Downloads The packaged Windows build and full Unreal Engine project are hosted externally because they exceed the submission platform's 950 MB upload limit. 
**Packaged Windows Build:** [Download from Google Drive](https://drive.google.com/file/d/1ZpzNO_szo1owwnqFMJ36stp-pVL39FWH/view?usp=sharing) 
**Full Unreal Engine Project:** SOURCE_LINK - **GitHub Repository:** https://github.com/ege-ozgur/phoenix-ascendant

## Project Overview

The game contains two playable levels and a complete gameplay flow:

**Main Menu → Story Screen → Level 1 → Level 2 → Victory**

Each level contains three enemy waves. After the final wave is cleared, the altar becomes active and allows the player to progress.

The main gameplay mechanic is elemental weakness:

- Fire deals increased damage to Ice enemies.
- Light deals increased damage to Shadow enemies.
- Using the incorrect power deals reduced damage.
- Healing is limited to three charges.

The project also includes a practical evaluation of Unreal Engine's Nanite rendering path using matched close and far camera positions.

## Features

- Third-person movement and camera controls
- Fire projectile attack
- Light line-trace attack
- Elemental weakness and resistance system
- Reusable C++ health and damage component
- Three-charge healing system
- Wave-based enemy spawning
- Ice and Shadow enemy variants
- Behavior Tree and Blackboard enemy AI
- NavMesh-based movement and pursuit
- Interactive altars and level progression
- Main menu, story screen, tutorial, pause menu, HUD, death screen, and victory screen
- Health, objective, wave, and healing-charge feedback
- Niagara and Cascade visual effects
- Combat, healing, death, ambient, and altar sound effects
- Nanite enabled/disabled performance comparison

## Requirements

### To Open the Source Project

- Windows 10 or Windows 11
- Unreal Engine 5.4.4
- Visual Studio 2022
- Visual Studio workload: **Desktop development with C++**
- Visual Studio components required for Unreal Engine development
- Git, when cloning the repository

A dedicated graphics card compatible with Unreal Engine 5 is recommended.

## Setup Instructions

1. Clone or download the repository.

```bash
git clone https://github.com/ege-ozgur/phoenix-ascendant.git
```

2. Open the project folder.
3. Right-click the `.uproject` file and select **Generate Visual Studio project files**.
4. Open the generated `.sln` file in Visual Studio 2022.
5. Set the build configuration to **Development Editor | Win64**.
6. Build the project.
7. Open the `.uproject` file with Unreal Engine 5.4.4.
8. Allow Unreal Engine to compile any missing modules when prompted.
9. Open the main menu map and press **Play**, or package the project for Windows.

When Unreal Engine reports stale or incompatible binaries, close the editor, delete the `Binaries` and `Intermediate` folders, regenerate the Visual Studio project files, and rebuild the project.

## Packaged Build

1. Extract the submitted Windows build.
2. Open the extracted folder.
3. Run the included `.exe` file.
4. Use the main menu to begin the game.

## Controls

| Input | Action |
|---|---|
| `W`, `A`, `S`, `D` | Move |
| Mouse | Look / Aim |
| Left Mouse Button | Fire attack |
| Right Mouse Button | Light attack |
| `R` | Heal |
| `Space` | Jump |
| `Esc` | Pause / Resume |

Fire is strongest against Ice enemies. Light is strongest against Shadow enemies.

## Gameplay Rules

### Damage

Each damageable actor uses `UHealthComponent`.

- Correct elemental power: `2.0x` damage
- Incorrect elemental power: `0.5x` damage
- Health is clamped between zero and maximum health
- Reaching zero health triggers the `OnDeath` event

### Healing

- The player begins with three healing charges.
- Healing cannot be used at full health.
- Healing cannot increase health above the maximum value.
- The HUD displays the remaining healing charges.

### Waves and Progression

Each level contains three waves:

- Wave 1: 3 enemies
- Wave 2: 4 enemies
- Wave 3: 6 enemies

The altar remains inactive until all waves are complete. Follow the on-screen objective to activate it. The first altar loads Level 2, while the final altar opens the victory screen.

## Project Architecture

The project uses C++ for reusable gameplay rules and Blueprints for configurable content, visual logic, and level flow.

### C++ Systems

- Player character logic
- `UHealthComponent`
- Damage calculation
- Elemental weakness handling
- Healing logic
- Death event broadcasting

### Blueprint Systems

- `BP_EnemyBase`
- `BP_EnemyIce`
- Enemy configuration
- Wave Manager
- Altar interaction
- Level transitions
- Behavior Tree tasks
- User interface widgets
- Visual and audio feedback

### Enemy AI

Enemy behaviour is implemented using:

- Behavior Trees
- Blackboards
- NavMesh
- Attack-distance checks
- Chase and attack branches
- Character-specific attack montages

## Main Maps and UI Flow

```text
Main Menu
    ↓
Story Screen
    ↓
Level 1
    ↓
Level 2
    ↓
Victory Screen
```

Additional interfaces include the tutorial screen, gameplay HUD, pause menu, and death screen.

## Testing and Debugging

The project was tested using functional checks, informal playtesting, and Unreal Engine debug visualisations.

Tested areas include:

- Elemental damage multipliers
- Health clamping
- Healing restrictions and charge usage
- Enemy death events
- AI pursuit and attacks
- Wave progression
- Altar activation
- Level transitions
- Death and restart flows
- HUD updates
- NavMesh and collision behaviour
- Nanite statistics and visualisation

Resolved issues included:

- Torch collision splitting the NavMesh
- Stale Live Coding binaries
- Duplicate components after Blueprint reparenting
- Incorrect health-bar calculation
- Repeated attack audio caused by missing cooldown gating

## Nanite Evaluation

The crypt environment was tested using:

```text
r.Nanite 1
r.Nanite 0
```

Matching close and far views were measured with:

```text
stat RHI
stat unit
```

The comparison evaluates the Nanite rendering path against the Nanite-disabled fallback path. It is not a direct comparison with separately authored traditional LOD chains.

The recorded results showed lower reported triangle counts and draw calls with Nanite enabled, while GPU time was higher in the tested editor scene. These results are specific to the tested environment, camera positions, effects, hardware, and editor conditions.

## External Assets and Credits

The project includes third-party content used for educational purposes.

### Epic Games / Unreal Engine Marketplace

- Paragon: Phase
- Paragon: Riktor
- Paragon: Aurora
- Ruined Crypt environment assets
- Torch-related assets
- Stylized Fire VFX

### Audio

- Mixkit
- Pixabay

### AI-Assisted Content

AI-generated images were used as backgrounds for the main menu, tutorial screen, and story screen.

The architecture and game-flow diagram used in the coursework report was produced with AI assistance and manually reviewed against the implemented project.

All third-party assets remain the property of their respective creators and are subject to their original licence terms.

## Repository

```text
https://github.com/ege-ozgur/phoenix-ascendant
```

## Author

**Ege Özgür**  
Student ID: 5745215  
University of Warwick  
WM9M6-30 Fundamentals of Games Research, Development and Management
