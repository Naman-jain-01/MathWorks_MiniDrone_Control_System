
# **Line Follower Algorithm for Parrot Mini Drone**

### **Team Name:** SCAL  
### **Institution:** Indian Institute of Information Technology, Guwahati  
### **Team Leader:** Naman Jain  
**Email:** [naman.jain@iiitg.ac.in](mailto:naman.jain@iiitg.ac.in)  
### **Members:**  
- **Ravi Patel** [ravi.patel21b@iiitg.ac.in](mailto:ravi.patel21b@iiitg.ac.in)  
- **Aayush Singh** [aayush.singh21b@iiitg.ac.in](mailto:aayush.singh21b@iiitg.ac.in)  
- **Aditya Krishna Jaiswal** [aditya.jaiswal22b@iiitg.ac.in](mailto:aditya.jaiswal22b@iiitg.ac.in)  

---

### **Introduction**

This repository contains a **line follower algorithm** designed for the **Parrot Mini Drone**, built using **Simulink MATLAB**. The algorithm enables the drone to autonomously track a **red line** and land on a designated **circle** using its onboard camera.

### Video Demonstration


![Simulation Demo](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/3fa8751a-a785-41a9-8567-53c4f4ddd4ac.gif)



---

### **Algorithm Overview**

#### **1. Line Detection and Heading Calculation**
- **Edge Detection** using the Canny edge filter to detect red lines.
- **Hough Line Transform** to extract straight lines.
- **Line Selection** to choose prominent lines representing the red line.
- **Heading Calculation** using the average of these lines.
![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Screenshot%202024-09-10%20011150.png)

#### **2. Bitmap-based Approach for Heading Adjustment**
- Define **Regions of Interest (ROIs)** in the camera feed.
- **Bitmap Intersection Analysis** to refine the drone's heading using the red line.
- **X-mark Generation** for more accurate trajectory stabilization.
![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Screenshot%202024-09-10%20011156.png)

![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Untitled%20video%20-%20Made%20with%20Clipchamp.gif)

#### **Landing Feature**
- **Circle Detection** using MATLAB’s `imfindcircles()` function.
- **Landing Decision** based on ROI detection.
![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Screenshot%202024-09-10%20011206.png)


---

#### Image Processing for Region of Interest
1. **Input**: The input to the system includes:
   - `centroid`: The center point of the object or path.
   - `centroid_blk`: The centroid of the black region (often used for boundary detection).
   - Other parameters like area, angle, and path history.

2. **Path Distance Calculation**: The system calculates the distance between the path coordinates and a reference point (`[80, 60]`), likely a fixed location in the frame, and computes various distances (`d1`, `d2`).
   - Based on these distances, the speed is adjusted dynamically (e.g., slower when the object is closer, faster when far).

3. **Projection and Path Correction**: If the current path deviates from the previous one, the system calculates the projected point using geometric transformations and checks for path correction by measuring angular deviations. The algorithm corrects the angle (`anglecorr`) depending on the path deviation and geometric orientation of the object relative to the frame’s center.

4. **Determining Region of Interest**: The algorithm generates a polygon (with `roicord_l` and `roicord_r`) that defines the region of interest around the path.
   - This is done by calculating left and right boundaries, using trigonometric functions to adjust the position based on the path angle.

5. **Black Region Detection**: In addition to the primary ROI, the system calculates `blackcord_l` and `blackcord_r`, representing the boundaries of black regions (likely obstacles or path edges) by inverting the angle (`+pi` shift) to compute opposite boundaries.

### Integration with Planning
- **Dynamic Speed Adjustment**: The speed is adjusted based on how far off the path the object is, which helps in smooth navigation.
- **Path Correction**: The system uses the image data to generate real-time corrections in the planned path by evaluating the ROI boundaries, ensuring the object stays on course.
- **Obstacle Avoidance**: The black region detection allows for planning around obstacles or boundaries by detecting edges of the path, which informs avoidance strategies.

### Enhanced README Explanation
You can enhance your README by adding the following points:

1. **Overview**: This project integrates image processing and navigation planning, combining real-time path detection and dynamic adjustment for autonomous systems.
   
2. **Image Processing**:
   - The system processes images to detect centroids of objects and black regions.
   - Distances between reference points and path coordinates are used to determine the trajectory.

3. **Region of Interest (ROI) Calculation**:
   - Using trigonometric projections, the algorithm defines the left and right boundaries of the path.
   - The ROI is dynamically adjusted based on the position of the centroid relative to the frame’s center.

4. **Path Planning**:
   - Real-time corrections are made based on deviations from previous paths.
   - Speed adjustments are applied based on the proximity of the object to the path, ensuring smooth navigation.

5. **Obstacle Avoidance**:
   - The system detects black regions representing boundaries or obstacles, using them to adjust the trajectory.
  
---

#### **In Detail about Path Planning Algorithims Employed**
**Overview**
This section describes the second path planning algorithm employed in our project, which is a critical part of guiding the system towards a target and performing precise maneuvers, especially during the landing phase. This algorithm leverages Vision-based Data inputs and state estimates, and is distinct from the first solution, which was implemented through Stateflow and State Machine Representation.

In contrast, the second approach utilizes user-defined MATLAB functions for dynamic decision-making, and sophisticated logic for path corrections and adjustments based on sensor inputs.

Inputs and Signals
The key input signals into the path planning subsystem include:

**Vision-based Data:**

This data is obtained from an image processing algorithm that tracks the environment in real-time.
It provides the X and Y coordinate increments required for object tracking, and circle increments, which help in precise positioning for landing.
To ensure the smooth functioning of the algorithm, the Butterworth 1st order filter with a cut-off frequency of 0.3 Hz is applied. This filter is essential for eliminating high-frequency noise, thus refining the incoming vision data.
Estimated Values:

These values represent estimations from the State Estimator, which calculates key system states such as position, velocity, and acceleration in the X, Y, and Z axes (denoted as x, y, and z in the diagram).
The estimated values are vital for predicting the current and future state of the system and guiding it towards the desired destination.

**MATLAB Function-based Logic**
In contrast to a more static State Machine, this path planning algorithm incorporates user-defined MATLAB functions, which allow for more dynamic and flexible path calculations. The core logic focuses on processing the filtered inputs and making real-time adjustments to the vehicle’s trajectory.

The vision-based data and estimated state values are processed by a Landing Logic block, which computes necessary actions based on the difference between the current position and the target position.
This block uses a combination of control theory principles and trajectory calculation algorithms to ensure that the vehicle is on track to reach the destination or to initiate a landing.
Path Planning Subsystem
The subsystem processes the input data in real-time, and its primary responsibility is generating reference commands that are used to adjust the vehicle's movement. The signals are fed through various functional blocks, including:

**Filter block (Butterworth filter) that smoothens incoming signals to reduce noise and prevent unstable path corrections.**
MATLAB Function block which computes necessary control actions like speed adjustments, heading changes, and precise landing maneuvers.
UpdateReferenceCmds: This is the final output bus that sends corrected position reference commands to the control system, ensuring that the vehicle follows the computed path.
---

### **System Requirements**
- **Hardware**: Parrot Mini Drone
- **Software**:  
  - MATLAB  
  - Simulink  
  - Computer Vision Toolbox  
- **Operating System**: Windows/macOS/Linux
- **Communication Interface**: Wi-Fi or Bluetooth

---

### **Usage Instructions**

1. **Drone Setup**: Ensure your drone is fully charged and connected to your system.
2. **MATLAB Configuration**: Open the MATLAB project. Install required toolboxes.
3. **Parameter Tuning**: Adjust camera settings and thresholds based on your drone’s environment.
4. **Run Algorithm**: Start the Simulink model to make the drone follow the red line.
5. **Performance Monitoring**: Observe the drone’s trajectory and fine-tune parameters.
6. **Optimization**: Modify code based on challenges like sharp turns or lighting.

---

### **Challenges Faced & Improvements**

#### **1. Handling Sharp Turns**  
The algorithm struggled with turns less than 60 degrees, causing the drone to overshoot.

**Improvement Suggestion**:  
Implementing a path prediction mechanism and adjusting speed dynamically during turns.

#### **2. Inefficient Circle Detection for Landing**  
Premature landing or missing the landing circle was common due to speed miscalculations.

**Improvement Suggestion**:  
Developing a dynamic ROI based on speed and trajectory would provide smoother landing decisions.

---

### **Experience and Acknowledgments**

Participating in the **MathWorks Mini Drone Competition** has been an exciting and challenging experience. Our team had the opportunity to work with cutting-edge image processing and control algorithms, learning to overcome challenges like sharp turns and efficient landings. The competition allowed us to collaborate, apply our technical knowledge, and expand our problem-solving skills.

Special thanks to **MathWorks** for organizing the event and giving us a platform to showcase our abilities. We also appreciate the support from our peers and mentors throughout the competition.

---

### **Snapshots and Video Demonstration**

[![](#image-of-path)](![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Screenshot%202024-09-10%20010021.png)
)  
*UI of Simulation*



---

### **References and Citations**

- **MathWorks Documentation**: [Link to official MATLAB/Simulink documentation](#)  
- **Related Research Paper**: [Research on Image Processing for Drones](#)

---

By following this structure, you'll make your README visually appealing with snapshots and videos, share your technical process, challenges, and personal experience, and ensure that all necessary information is provided for anyone looking to replicate or learn from your project.

Let me know if you'd like assistance with formatting or any specific section further!


Welcome to the Mini Drone Competition! Follow the instructions below to set up and run the simulation in MATLAB.

## Setup Instructions

1. **Download the ZIP File**:
   - Download the project ZIP file from the provided link or repository.

2. **Unzip the File**:
   - Unzip the downloaded file. This will extract the necessary files and folders.

3. **Move to MATLAB Project Path**:
   - Copy the unzipped folder and paste it into your MATLAB project path. This ensures that all the files are correctly referenced.

4. **Run the Simulation**:
   - Open MATLAB.
   - Navigate to the project path where you pasted the unzipped folder.
   - Locate and open the `MinidroneCompetition.prj` file in MATLAB.
   - Follow the on-screen instructions to start the simulation.

## Notes

- Ensure that you have the necessary MATLAB toolboxes installed for running the simulation which includes
- ![image](https://github.com/user-attachments/assets/d11f9bcb-e0e1-4ff0-a8c1-55adb891c6af)
- If you encounter any issues, refer to the documentation or contact the support team for assistance.
