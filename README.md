To create an attractive and comprehensive README for your MathWorks Mini Drone Competition project, here's a well-structured approach that incorporates your algorithm description, challenges, usage instructions, images, videos, and your personal experience. You can then use markdown (.md) format to create it. Below is an enhanced version of your README.

---

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

### Video Demonstration

[Watch the video on Google Drive](https://drive.google.com/file/d/1oqsha61gUzGygEiQRGJikwqs8xbmVV3E/view?usp=sharing)


![Drone Path Snapshot](#link-to-image)  

---

### **Algorithm Overview**

#### **1. Line Detection and Heading Calculation**
- **Edge Detection** using the Canny edge filter to detect red lines.
- **Hough Line Transform** to extract straight lines.
- **Line Selection** to choose prominent lines representing the red line.
- **Heading Calculation** using the average of these lines.

#### **2. Bitmap-based Approach for Heading Adjustment**
- Define **Regions of Interest (ROIs)** in the camera feed.
- **Bitmap Intersection Analysis** to refine the drone's heading using the red line.
- **X-mark Generation** for more accurate trajectory stabilization.

#### **Landing Feature**
- **Circle Detection** using MATLAB’s `imfindcircles()` function.
- **Landing Decision** based on ROI detection.

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

[![](#image-of-path)](#link-to-image)  
*Drone following the red line with live snapshots of the path*

### Video Demonstration

<video width="600" controls>
  <source src="https://drive.google.com/uc?export=download&id=1oqsha61gUzGygEiQRGJikwqs8xbmVV3E" type="video/mp4">
  Your browser does not support the video tag.
</video>


*A video demonstrating the drone's behavior following the red line and landing*

---

### **References and Citations**

- **MathWorks Documentation**: [Link to official MATLAB/Simulink documentation](#)  
- **Related Research Paper**: [Research on Image Processing for Drones](#)

---

By following this structure, you'll make your README visually appealing with snapshots and videos, share your technical process, challenges, and personal experience, and ensure that all necessary information is provided for anyone looking to replicate or learn from your project.

Let me know if you'd like assistance with formatting or any specific section further!


![image](https://github.com/user-attachments/assets/9bcda76d-9841-49e2-baea-869c6a6f3776)# Mini Drone Competition

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
