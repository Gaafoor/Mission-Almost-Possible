# :robot::video_camera: Building an AI for Real-Time Exercise Recognition using Computer Vision & Deep Learning :weight_lifting_man::muscle:

[Watch the demo video](https://drive.google.com/file/d/190yJZmMPF5FlfZEEBwX8gy4grPI662Ka/view?usp=drive_link)

## Description
In this project, I designed an AI that uses webcam footage to accurately detect exercises in real time and counts reps. OpenCV is used to access the webcam on your machine, a pretrained CNN is implemented for real-time pose estimation, and custom deep learning models are built using TensorFlow/Keras to recognize what exercise is being performed. In addition, this project includes a guided data collection pipeline which is used to generate training data for the custom deep learning models. Using my data, the LSTM model achieved an accuracy score of 97.78% and a categorical cross-entropy loss of 1.51e-3 on the validation dataset. The attention-based LSTM achieved an accuracy score of 100% and a categorical cross-entropy loss of 2.08e-5 on the validation dataset. From that point, joint angles are extracted from the pose estimation coordinates and heuristics are used to track the exercise and count reps. Finally, visualization tools are included that display joint angles, rep counts, and probability distributions. 

## Installation
- Download this repository and move it to your desired working directory
- Download Anaconda if you haven't already
- Open the Anaconda Prompt
- Navigate to your working directory using the cd command
- Run the following command in the Anaconda prompt:
	```
  	conda env create --name NAME --file environment.yml
  	```
	where NAME needs to be changed to the name of the conda virtual environment for this project. This environment contains all the package installations and dependencies for this project.
  
- Run the following command in the Anaconda prompt:
  	```
  	conda activate NAME
  	```
	This activates the conda environment containing all the required packages and their versions. 
  
- Open Anaconda Navigator
- Under the "Applications On" dropdown menu, select the newly created conda environment
- Install and open Jupyter Notebook. NOTE: once you complete this step and if you're on a Windows device, you can call the installed version of Jupyter Notebook within the conda environment directly from the start menu.  
- Navigate to the ExerciseDecoder.ipynb file within the repository

## Features

- Implementation of Google MediaPipe's BlazePose model for real-time human pose estimation
- Computer vision tools (i.e., OpenCV) for color conversion, detecting cameras, detecting camera properties, displaying images, and custom graphics/visualization 
- Inferred 3D joint angle computation according to relative coordinates of surrounding body landmarks
- Guided training data generation
- Data preprocessing and callback methods for efficient deep neural network training
- Customizable LSTM and Attention-Based LSTM models
- Real-time visualization of joint angles, rep counters, and probability distribution of exercise classification predictions

## Credits
- https://github.com/chrisprasanna/Exercise_Recognition_AI
- [MediaPipe Pose](https://google.github.io/mediapipe/solutions/pose.html) for the pretrained human pose estimation model
- [Nicholas Renotte](https://github.com/nicknochnack) for tutorials on real-time action detection and pose estimation
- [Philippe Rémy](https://github.com/philipperemy/keras-attention-mechanism) for the attention mechanism implementation for Keras

## License
[MIT](https://github.com/chrisprasanna/Exercise_Recognition_AI/blob/main/LICENSE)
