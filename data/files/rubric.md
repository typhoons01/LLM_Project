### Rubric for Evaluating Binary Search Tree with Linked Lists Assignment

---


<!-- ### Marking Scheme to be considered for each question

- Execution and Correctness (50%): Focuses on whether the program works correctly, meets all functional requirements, and produces the expected output.  
- Logic (45%): Evaluates the clarity and accuracy of the underlying logic, ensuring it aligns with the problem specifications.  
- Presentability (5%): Assesses code readability, organization, and documentation quality.   -->

### Marks division and Functionalities to be evaluated

#### 1. Program Correctness and Functionality (50 marks)

- *Building the Binary Search Tree (20 marks)*  
  - File Reading and Data Handling (10 marks)  
    - Accurately reads the input file file1.txt and retrieves the number of records and corresponding data (5 marks).  
    - Correctly constructs a Binary Search Tree (BST) where each node stores a linked list, using the first integer in each line as the key (5 marks).  

  - BST Structure Validation (10 marks)  
    - Ensures that the BST adheres to the properties of binary search trees (5 marks).  
    - Verifies that each linked list is accurately inserted into the BST nodes (5 marks).  

- *Sorting the Linked Lists (17 marks)*  
  - Sorting Algorithm Implementation (10 marks)  
    - Implements a sorting algorithm of choice to sort each linked list starting from the second node without modifying the first node (5 marks).  
    - Correctly sorts all linked lists stored in the BST nodes as per specifications (5 marks).  

  - Sorting Logic and Efficiency (7 marks)  
    - Demonstrates logical and efficient sorting of the linked lists (4 marks).  
    - Handles edge cases such as empty lists or lists with a single node appropriately (3 marks).  

- *In-order Traversal and File Writing (17 marks)*  
  - Traversal Implementation (10 marks)  
    - Implements an in-order traversal of the BST to visit each node in the correct order (5 marks).  
    - Traversal outputs each linked list to file2.txt, with one linked list per line as described in the sample (5 marks).  

  - Output Accuracy (7 marks)  
    - Ensures output format strictly matches the sample provided (5 marks).  
    - Handles special cases such as empty nodes or incomplete traversal (2 marks).  

- *Main Function (6 marks)*  
  - Program Execution Flow (6 marks)  
    - Drives the program in the required sequence: reading input, constructing the BST, sorting the lists, performing in-order traversal, and generating output (6 marks).  

---

#### 2. Code Quality and Style (8 marks)

- *Readability and Documentation (4 marks)*  
  - Proper use of indentation, consistent spacing, and meaningful variable names (2 marks).  
  - Includes well-written comments explaining the logic, especially for critical sections like file handling, BST construction, and sorting (2 marks).  

- *Modularity and Organization (4 marks)*  
  - Adheres to modularity by implementing the specified functions (readData(), sortLists(), traverse(), and main()) with clear separation of logic (2 marks).  
  - Uses reusable code structures and avoids unnecessary duplication of logic (2 marks).  

---

#### 3. Adherence to Assignment Constraints (2 marks)

- *Function Names and Specifications (2 marks)*  
  - Implements all required functions with the exact names (readData(), sortLists(), traverse(), and main()), ensuring functionality matches the problem description (2 marks).  

---



---

*Total Marks Awarded = Sum of marks from all sections above*

---

### Note to Evaluators

- *Partial Credit:* Award partial marks for attempts that demonstrate effort or partial correctness, even if the full functionality is not achieved. For instance, if a linked list is sorted but includes errors, assign partial marks.  
- *Modular Structure:* Deduct marks for failing to implement the program in the specified modular format or deviating from required function names.  
- *Adherence to Output Format:* Ensure that the output file strictly matches the sample provided in the problem description.  
- *Originality and Contextual Relevance:* No marks for logically correct statements or code fragments that do not align with the problem requirements.