<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

Here's a blank template to get started. To avoid retyping too much info, do a search and replace with your text editor for the following: `github_username`, `repo_name`, `twitter_handle`, `linkedin_username`, `email_client`, `email`, `project_title`, `project_description`, `project_license`

<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Prerequisites

Assure that CMake and an appropriate C/C++ compiler is installed on the system.

### Installation

1. Clone the repo 
   ```sh
   git clone https://github.com/neoaces/ceotest
   ```
2. cd into the directory
   ```sh
   cd ceotest
   ```
3. Create a build directory
   ```sh
   mkdir build
   cd build
   ```
4. Run the build
   ```sh
   cmake --build .
   ```
5. Run the executable
   ```sh
   ./src/neophys
   ```


<!-- USAGE EXAMPLES -->
## Usage

The program uses **raylib** to handle the graphics in the window. Upon execution, the window will enter the test mode, and you will be presented with the values of the test object (coordinates, mass, size). Use the slider bars to adjust the initial conditions before the simulation is run.

Run the simulation with the button in the top-left menu.

## Theory

neophys runs off of the RK4 solver algorithm, and uses the concept of "force accumulators", mainly based off [Physically Based Modeling: Principles and Practice](https://www.cs.cmu.edu/~baraff/sigcourse/).

The program itself relies on raylib to handle both graphics and UI/UX, which allows me to focus on the logic instead of the graphics, as in the first prototype [ceophys-v1](https://github.com/neoaces/ceophys-v1).

<!-- ROADMAP -->
## Roadmap

- [ ] Gravity, spring, and normal force
- [ ] Multiple particle support
- [ ] Simulation start and stop


See the [open issues](https://github.com/neoaces/ceotest/issues) for a full list of proposed features (and known issues).

<!-- CONTACT -->
## Contact

Anzle Chavez - [linktr.ee/neocodes](https://linktr.ee/neocodes) - anzlemchavez@gmail.com

Project Link: [neoaces/ceotest](https://github.com/neoaces/ceotest)