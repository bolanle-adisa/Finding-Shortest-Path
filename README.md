# Finding-Shortest-Path
Create a tool that would tell Mary the shortest route among the patients she must visit. 
Mary never knows how many patients she must visit but is always given the distances between patients. 
Mary’s hospital has tried to be helpful by giving her a list like this:     
Mary -> Henry = 4  
Mary -> Jane = 6  
Mary -> Quinn = 20  
Henry -> Jane = 10  
Quinn -> Jane = 8     T
he list is in the form:  Person A -> Person B = Distance between Person A and Person B  
*If a distance is not given between patients, it is assumed that it is not possible to commute between them.  
*The list is supplied to Mary in a .txt file called patientList.txt.     
Your Task  - Use the patientList.txt file given by the hospital, to find the shortest route to the patients that Mary must visit. 
- Your solution should cater for n number of patients.  
- Your user-defined variables, functions, classes, and packages should end with your initials.       
Hints:  Use a Graph data structure to handle the patients.  
Create an adjacency list and use a depth-first search or breath-first search algorithm to find the paths.
