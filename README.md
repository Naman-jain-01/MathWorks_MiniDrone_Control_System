
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
![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Snapshots/Screenshot%202024-09-10%20011150.png)

---

#### **2. Bitmap-based Approach for Heading Adjustment**
- Define **Regions of Interest (ROIs)** in the camera feed.
- **Bitmap Intersection Analysis** to refine the drone's heading using the red line.
- **X-mark Generation** for more accurate trajectory stabilization.
![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Snapshots/Screenshot%202024-09-10%20011156.png)

---

![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Untitled%20video%20-%20Made%20with%20Clipchamp.gif)

---

#### **Landing Feature**
- **Circle Detection** using MATLAB’s `imfindcircles()` function.
- **Landing Decision** based on ROI detection.
![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Snapshots/Screenshot%202024-09-10%20011206.png)


---
## Image Processing and Path Planning for Region of Interest

---

#### **1. Introduction**
This project combines real-time **image processing** with advanced **path planning** algorithms to guide an autonomous system. The system detects objects, processes visual data, adjusts its path dynamically, and avoids obstacles, all while maintaining a safe and efficient route.

![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Snapshots/Screenshot%202024-09-10%20022123.png)

---

### **2. Image Processing for Region of Interest (ROI)**

#### **2.1. Input**
The system receives several key inputs for image processing:
   - **Centroid**: The center point of the detected object or path.
   - **Centroid\_blk**: The centroid of the black region, often used for boundary detection.
   - **Other Parameters**: Including area, angle, and path history, which contribute to path planning and adjustments.


#### **2.2. Path Distance Calculation**
   - The system calculates the distance between the current path and a reference point (typically `[80, 60]`).
   - Using these distances (e.g., `d1`, `d2`), the system adjusts speed dynamically:
     - **Closer**: Slows down when the object is near.
     - **Farther**: Speeds up when the object is distant.

#### **2.3. Projection and Path Correction**
   - If the current path deviates from the intended route, the system calculates a projected point using geometric transformations.
   - Angular deviations are measured, and corrections are applied by adjusting the **angle correction** (`anglecorr`), ensuring the object remains aligned with the path.

#### **2.4. Defining the Region of Interest (ROI)**
   - The algorithm defines an ROI around the path using left and right boundary points (`roicord\_l` and `roicord\_r`).
   - Trigonometric functions are used to calculate these boundaries, ensuring that the object remains centered within the frame.


#### **2.5. Black Region Detection**
   - **Black Region Boundaries**: Additional boundaries (`blackcord\_l`, `blackcord\_r`) are calculated to detect black regions, often representing obstacles or path edges.
   - An angular shift of `+π` is applied to compute the opposite boundaries of these regions.


---

### **3. Path Planning Algorithm**

![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Snapshots/Screenshot%202024-09-10%20020336.png)

#### **3.1. Dynamic Speed Adjustment**
   - The system uses path distance calculations to adjust the speed of the object. As the distance between the object and the path changes, the speed dynamically adapts to ensure smooth navigation.

#### **3.2. Path Correction Mechanism**
   - **Real-Time Path Correction**: The system evaluates the current path based on image data and previous path coordinates. Any deviation results in an immediate adjustment of the planned trajectory.
   - **Angular Adjustments**: The system computes angular deviations and applies corrections to ensure that the object maintains a straight path towards the destination.

#### **3.3. Obstacle Detection and Avoidance**
   - **Black Region Detection**: The black regions detected represent potential obstacles or boundaries.
   - The system uses this information to plan avoidance maneuvers, ensuring that the object avoids straying off course or colliding with obstacles.

---

### **4. Detailed Overview of the Path Planning Algorithm**

#### **4.1. Key Inputs and Signals**

- **Vision-Based Data**:
   - Real-time tracking of the environment through image processing, providing X and Y coordinate increments and precise positional data.
   - **Butterworth Filter**: A 1st order Butterworth filter with a 0.3 Hz cutoff frequency is applied to smooth out noise in the data.

- **Estimated Values**:
   - Derived from the state estimator, these values include the system's position, velocity, and acceleration in the X, Y, and Z axes.

#### **4.2. MATLAB Function-Based Logic**
   - The path planning algorithm leverages user-defined MATLAB functions for dynamic and flexible path calculations.
   - These functions process filtered inputs and generate real-time trajectory adjustments.

   - The **Landing Logic Block** uses control theory principles and trajectory algorithms to ensure accurate path corrections, guiding the object to its destination or landing point.

#### **4.3. Path Planning Subsystem**

![image](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/blob/main/Snapshots/Screenshot%202024-09-10%20022155.png)

   - The subsystem processes incoming data and generates reference commands to adjust the object's movement.
   - Key components include:
     - **Filter Block**: Smoothens incoming signals to reduce noise and ensure stable path corrections.
     - **MATLAB Function Block**: Computes control actions such as speed adjustments, heading changes, and precise landing maneuvers.
     - **UpdateReferenceCmds**: Sends corrected position reference commands to the control system.

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

#### **Key Features:**
- Real-time ROI calculation and path correction
- Dynamic speed adjustment for smooth navigation
- Obstacle detection and avoidance through black region analysis
- Robust path planning algorithm using MATLAB functions for dynamic decision-making

---

### **5. Conclusion**
This project demonstrates the integration of image processing and path planning to create a robust autonomous system. By detecting and analyzing visual data in real-time, the system dynamically adjusts its path, avoids obstacles, and navigates efficiently towards its destination.

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


### **References and Citations**

- **MathWorks Documentation**: [Link to official MATLAB/Simulink documentation](https://in.mathworks.com/content/dam/mathworks/mathworks-dot-com/academia/student-competitions/minidrone-competition/mathworks-minidrone-competition-guidelines.pdf)  
- **Related Research Paper**: [Research on Image Processing for Drones](https://github.com/Naman-jain-01/MathWorks_MiniDrone_Control_System/raw/main/CEPPI-THESIS-2020.pdf)

---

By following this structure, you'll make your README visually appealing with snapshots and videos, share your technical process, challenges, and personal experience, and ensure that all necessary information is provided for anyone looking to replicate or learn from your project.

### **Experience and Acknowledgments**

Participating in the **MathWorks Mini Drone Competition** has been an exciting and challenging experience. Our team had the opportunity to work with cutting-edge image processing and control algorithms, learning to overcome challenges like sharp turns and efficient landings. The competition allowed us to collaborate, apply our technical knowledge, and expand our problem-solving skills.

Special thanks to **MathWorks** for organizing the event and giving us a platform to showcase our abilities. We also appreciate the support from our peers and mentors throughout the competition.

---

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

![image](https://github.com/user-attachments/assets/d11f9bcb-e0e1-4ff0-a8c1-55adb891c6af)
- If you encounter any issues, refer to the documentation or contact the support team for assistance.
