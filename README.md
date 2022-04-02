# K-Nearest-Neighbors-KNN

# Design

In my project I used three classes(Point, KNN, Graph) to test samples with K-Nearest Neighbors 
classification algorithm (k-NN).

## Point

These class objects are designed to store categories, features, indexes and distance of our 30 training 
samples and 10 test sample.



## KNN

This class categorizes test samples using the K-Nearest Neighbors classification algorithm.
First of all, the K value entered by the user in the constructer is set. If an invalid number (negative) is 
entered by the user during the assignment of the K value, a warning message will be printed on the 
terminal screen and the value will be K=3.
30 training samples are created with the help of the createSamplesPoint() function in the 
Constructer.During this process, I followed two different methods. First, I created Point's objects in 
the loop and sent the index , category information and randomly generated features information. 
After seeing that some properties overlap within the same category, I created 30 different property 
values using the set container as the 2nd method (it stays as a comment line in the code). I pulled 
properties from the set container to the Point objects. I store the created Points’ objects in a samples 
vector.
With the help of the CreateTestingPoint() function, I created the Testing points randomly and store 
them as the objects of the Point class in the testing Points vector.

### KNNRun() ->
With this function, the k-NN algorithm starts working and the samples and testingPoint vector 
created go to the classifyAPoint() function


### ClassifyAPoint() -> 
First of all, in this function, the stored test points are taken one by one and their distances to the 
training samples points are calculated and store the ditance value in the point object. 
Then the samples vector is sorted from the largest to the smallest using the distances calculated with 
the sort algorithm. Objects are get from the vector sorted according to the K value entered by the 
user and it is determined how many from each category. These are assigned to the freq vector and 
the categories of testingPoints are determined with the help of this vector.


## Graph
The Graph class will be used to store the graph and this class will visualize the k-NN algorithms result 
we created with the member functions using the opencv library.
After visual arrangements are made on the image, the samples, which are divided into categories by 
considering 2 features on the x , y axis, appear in the first image. 
Then uncategorized test examples and training examples appear in second image.
In the result image, the test samples are divided into categories.
Category figure information is given in the lower left part of the image.


# Implementation

The project was built using Visual Studio 2022.
Libraries: Opencv 4.2.0

### Step-1
Our project is opened with the Visual Studio IDE by running the Project.sln file in the 
project file.

### Step-2
The project is run with the Windows debugger.

![image](https://user-images.githubusercontent.com/83959816/161401323-5d82f343-887f-4c21-b720-b2c67992b85f.png)


### Step-3
After the Project is run, k-NN algorithm to work, the user's K value is requested from the terminal 
screen

![image](https://user-images.githubusercontent.com/83959816/161401330-accf02bc-3182-4293-b0f5-e796a6ed1595.png)


### Step-4
Index, feature and category information of 30 training examples are printed on the terminal screen. 
Then, uncategorized test samples were printed

![image](https://user-images.githubusercontent.com/83959816/161401337-1a63b463-d957-40e4-b47c-2b38a2e48e77.png)



### Step-5
After the knn algorithm runs, 30 trained samples and 10 categorized test samples are written to the 
terminal screen.

![image](https://user-images.githubusercontent.com/83959816/161401346-9c8aafa1-22aa-4f79-ad52-079b134f9e81.png)


### Step-6
Outputs printed on the terminal screen were visualized using version 4.2.0 of the OpenCV library. It is 
shown step by step in three separate windows and category information is given as a figure under 
the images.

![image](https://user-images.githubusercontent.com/83959816/161401359-248900d9-2560-411a-9af9-67bbb2ac6134.png)

![image](https://user-images.githubusercontent.com/83959816/161401362-fc02c74b-0bb8-4aaf-851a-ddbc9e9075af.png)



## Step-7
Optionally, if the comment line in the code is removed and the trained points are assigned with the 
set container, the outputs are as follows.


![image](https://user-images.githubusercontent.com/83959816/161401366-e19c9f5d-6db1-48df-a035-efc1d0b6d300.png)























