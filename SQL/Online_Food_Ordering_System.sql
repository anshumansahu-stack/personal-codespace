CREATE DATABASE Online_Food_Ordering_System;
USE Online_Food_Ordering_System;
CREATE TABLE Customer (
    customer_id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    phone VARCHAR(15) UNIQUE NOT NULL,
    email VARCHAR(50) UNIQUE,
    address VARCHAR(200)
);
INSERT INTO Customer (customer_id, name, phone, email, address) VALUES
(1, 'Rahul Sharma', '9876543210', 'rahul@mail.com', 'Hyderabad'),
(2, 'Priya Jain', '9123456780', 'priya@mail.com', 'Warangal'),
(3, 'Aman Verma', '9988776655', 'aman@mail.com', 'Hanamkonda'),
(4, 'Sneha Reddy', '9865321470', 'sneha@mail.com', 'Secunderabad'),
(5, 'Vikram Singh', '9012345678', 'vikram@mail.com', 'Hyderabad'),
(6, 'Anjali Mehta', '9345678123', 'anjali@mail.com', 'Warangal'),
(7, 'Rohit Yadav', '9800123456', 'rohit@mail.com', 'Hyderabad'),
(8, 'Harsha G', '9678452310', 'harsha@mail.com', 'Kazipet'),
(9, 'Lakshmi N', '9558044332', 'lakshmi@mail.com', 'Hanamkonda'),
(10,'Sanjay Rao', '9765412300', 'sanjay@mail.com', 'Warangal');
CREATE TABLE Restaurant (
    restaurant_id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    location VARCHAR(100),
    rating DECIMAL(2,1) CHECK (rating BETWEEN 1 AND 5)
);
INSERT INTO Restaurant (restaurant_id, name, location, rating) VALUES
(1, 'Spice Hub', 'Hyderabad', 4.6),
(2, 'Tandoori Treats', 'Warangal', 4.2),
(3, 'Biryani Palace', 'Hanamkonda', 4.8),
(4, 'Punjabi Rasoi', 'Hyderabad', 4.5),
(5, 'Urban Tadka', 'Kazipet', 4.3),
(6, 'South Spice', 'Secunderabad', 4.0),
(7, 'Flavors of India', 'Hyderabad', 4.7),
(8, 'Chaats Street', 'Warangal', 4.1),
(9, 'Veg Delight', 'Hanamkonda', 4.4),
(10,'Grill Masters', 'Hyderabad', 4.6);
CREATE TABLE Menu_Item (
    item_id INT PRIMARY KEY,
    restaurant_id INT,
    item_name VARCHAR(80) NOT NULL,
    price DECIMAL(7,2) NOT NULL CHECK (price > 0),
    category VARCHAR(50),
    FOREIGN KEY (restaurant_id) REFERENCES Restaurant(restaurant_id)
);
INSERT INTO Menu_Item (item_id, restaurant_id, item_name, price, category) VALUES
-- Restaurant 1
(1,1,'Paneer Butter Masala',220,'Main Course'),
(2,1,'Veg Biryani',180,'Rice'),
(3,1,'Butter Roti',20,'Bread'),

-- Restaurant 2
(4,2,'Chicken Tandoori',300,'Starter'),
(5,2,'Butter Naan',25,'Bread'),
(6,2,'Dal Fry',150,'Main Course'),

-- Restaurant 3
(7,3,'Hyderabadi Biryani',250,'Rice'),
(8,3,'Chicken 65',200,'Starter'),
(9,3,'Gulab Jamun',40,'Dessert'),

-- Restaurant 4
(10,4,'Chole Bhature',120,'Main Course'),
(11,4,'Lassi',60,'Beverage'),
(12,4,'Aloo Paratha',80,'Breakfast'),

-- Restaurant 5
(13,5,'Veg Noodles',140,'Chinese'),
(14,5,'Manchurian',160,'Chinese'),
(15,5,'Lime Soda',40,'Beverage'),

-- Restaurant 6
(16,6,'Masala Dosa',90,'South Indian'),
(17,6,'Idli Sambar',60,'South Indian'),
(18,6,'Filter Coffee',40,'Beverage'),

-- Restaurant 7
(19,7,'Mutton Curry',280,'Main Course'),
(20,7,'Chicken Curry',240,'Main Course'),
(21,7,'Jeera Rice',100,'Rice'),

-- Restaurant 8
(22,8,'Pani Puri',50,'Snack'),
(23,8,'Bhel Puri',60,'Snack'),
(24,8,'Samosa',20,'Snack'),

-- Restaurant 9
(25,9,'Veg Thali',150,'Main Course'),
(26,9,'Curd Rice',80,'Rice'),
(27,9,'Rasgulla',30,'Dessert'),

-- Restaurant 10
(28,10,'Grilled Chicken',260,'Main Course'),
(29,10,'French Fries',90,'Snack'),
(30,10,'Cold Coffee',70,'Beverage');
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    restaurant_id INT,
    order_date DATE NOT NULL,
    status VARCHAR(20) CHECK (status IN ('Placed','Preparing','Delivered','Cancelled')),
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id),
    FOREIGN KEY (restaurant_id) REFERENCES Restaurant(restaurant_id)
);
INSERT INTO Orders (order_id, customer_id, restaurant_id, order_date, status) VALUES
(101,1,3,'2025-11-01','Delivered'),
(102,2,1,'2025-11-02','Preparing'),
(103,3,4,'2025-11-02','Delivered'),
(104,4,5,'2025-11-03','Delivered'),
(105,5,7,'2025-11-03','Cancelled'),
(106,6,2,'2025-11-04','Delivered'),
(107,7,10,'2025-11-04','Delivered'),
(108,8,6,'2025-11-05','Preparing'),
(109,9,8,'2025-11-05','Delivered'),
(110,10,9,'2025-11-06','Delivered');
CREATE TABLE Order_Item (
    order_item_id INT PRIMARY KEY,
    order_id INT,
    item_id INT,
    quantity INT CHECK (quantity > 0),
    FOREIGN KEY (order_id) REFERENCES Orders(order_id),
    FOREIGN KEY (item_id) REFERENCES Menu_Item(item_id)
);
INSERT INTO Order_Item (order_item_id, order_id, item_id, quantity) VALUES
(1,101,7,1),
(2,101,9,2),
(3,102,1,1),
(4,103,10,2),
(5,104,14,1),
(6,105,19,1),
(7,106,4,2),
(8,107,28,1),
(9,108,16,2),
(10,109,22,3);
CREATE TABLE Delivery_Person (
    delivery_id INT PRIMARY KEY,
    name VARCHAR(50),
    phone VARCHAR(15) UNIQUE,
    status VARCHAR(20) CHECK (status IN ('Available','Busy'))
);
INSERT INTO Delivery_Person (delivery_id, name, phone, status) VALUES
(1,'Ramesh','9000012345','Available'),
(2,'Suresh','9000011111','Busy'),
(3,'Mahesh','9000012222','Available'),
(4,'Lokesh','9000013333','Busy'),
(5,'Naresh','9000014444','Available'),
(6,'Pradeep','9000015555','Available'),
(7,'Raghu','9000016666','Busy'),
(8,'Shankar','9000017777','Available'),
(9,'Gopal','9000018888','Busy'),
(10,'Kiran','9000019999','Available');
CREATE TABLE Payment (
    payment_id INT PRIMARY KEY,
    order_id INT UNIQUE,
    amount DECIMAL(10,2) CHECK (amount > 0),
    mode VARCHAR(20) CHECK (mode IN ('UPI','Card','Cash')),
    payment_date DATE,
    FOREIGN KEY (order_id) REFERENCES Orders(order_id)
);
INSERT INTO Payment (payment_id, order_id, amount, mode, payment_date) VALUES
(1,101,330,'UPI','2025-11-01'),
(2,102,200,'Card','2025-11-02'),
(3,103,240,'Cash','2025-11-02'),
(4,104,160,'UPI','2025-11-03'),
(5,105,280,'Card','2025-11-03'),
(6,106,300,'UPI','2025-11-04'),
(7,107,260,'Card','2025-11-04'),
(8,108,180,'UPI','2025-11-05'),
(9,109,150,'Cash','2025-11-05'),
(10,110,120,'UPI','2025-11-06');
CREATE TABLE Review (
    review_id INT PRIMARY KEY,
    customer_id INT,
    restaurant_id INT,
    rating INT CHECK (rating BETWEEN 1 AND 5),
    comments VARCHAR(200),
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id),
    FOREIGN KEY (restaurant_id) REFERENCES Restaurant(restaurant_id)
);
INSERT INTO Review (review_id, customer_id, restaurant_id, rating, comments) VALUES
(1,1,3,5,'Amazing biryani!'),
(2,2,1,4,'Good food, fast delivery'),
(3,3,4,5,'Loved the taste'),
(4,4,5,4,'Chinese items were great'),
(5,5,7,3,'Spicy but tasty'),
(6,6,2,4,'Nice tandoori chicken'),
(7,7,10,5,'Best grilled chicken ever'),
(8,8,6,4,'Dosa was crispy'),
(9,9,8,3,'Snacks were okay'),
(10,10,9,5,'Excellent veg thali');

-- ALL TABLES CREATED
