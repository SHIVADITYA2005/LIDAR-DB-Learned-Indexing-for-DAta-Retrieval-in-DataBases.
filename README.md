# L-Index: Machine Learning Accelerated DBMS Indexing

L-Index is a high-performance database indexing prototype that explores the intersection of systems programming and machine learning. This project implements a **Learned Index Structure**, replacing traditional $O(\log n)$ search structures (like B-Trees) with a predictive model that "learns" the data distribution to accelerate record retrieval.

## 🚀 The Core Innovation
Traditional indexing relies on rigid tree structures. L-Index treats indexing as a regression problem:
* **Feature Engineering:** A custom-built encoder transforms string-based primary keys into numerical vectors using a base-26 polynomial mapping.
* **Neural-Inspired Regression:** A Linear Regression model, trained from scratch via Gradient Descent, predicts the physical address of a record in $O(1)$ time.
* **Hybrid Retrieval:** To ensure 100% accuracy, the system uses the model's prediction to define a narrow search window. It then performs a localized binary search within calculated **true error bounds**, guaranteeing data integrity while minimizing CPU cycles.

## 🛠️ Technical Highlights
* **Zero Dependencies:** The entire ML pipeline—including the optimizer, loss functions, and feature encoders—is implemented in pure C++17.
* **Performance-Driven:** Designed to reduce the memory footprint of large-scale indices by replacing millions of pointers with a few lightweight model weights.
* **Capstone Rigor:** Includes automated testing for "True Error Bounds" and success-rate validation across randomized datasets.

## 📁 Project Structure
* `/src`: Core implementation including the Gradient Descent model and search logic.
* `/include`: Decoupled headers for modularity and professional code organization.
* `/data`: Support for large-scale text-based datasets.

## ⚙️ Installation & Usage
1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/SHIVADITYA2005/LIDAR-DB-Learned-Indexing-for-DATA-Retrieval-in-DataBases.git](https://github.com/SHIVADITYA2005/LIDAR-DB-Learned-Indexing-for-DATA-Retrieval-in-DataBases.git)
   cd LIDAR-DB-Learned-Indexing-for-DATA-Retrieval-in-DataBases
