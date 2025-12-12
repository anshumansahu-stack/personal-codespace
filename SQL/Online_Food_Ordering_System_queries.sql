-- MEANINGFUL OPERATIONS
SET SQL_SAFE_UPDATES=0;
-- 1. INSERT A NEW ORDER
INSERT INTO Orders (order_id, customer_id, restaurant_id, order_date, status)
VALUES (111, 1, 1, CURRENT_DATE, 'Placed');

-- 2. UPDATE RESTAURANT RATING
UPDATE Restaurant
SET rating = 4.7
WHERE restaurant_id = 1;

-- 3. DELETE CANCELLED ORDERS
DELETE FROM Payment
WHERE order_id IN (
    SELECT order_id FROM Orders WHERE status = 'Cancelled'
);
DELETE FROM Order_Item
WHERE order_id IN (
    SELECT order_id FROM Orders WHERE status = 'Cancelled'
);
DELETE FROM Orders
WHERE status = 'Cancelled';

-- 4. LIST ALL MENU ITEMS OF THE RESTAURANT
SELECT item_name, price
FROM Menu_Item
WHERE restaurant_id = 2;

-- 5. FIND TOTAL SALES PER RESTAURANT
SELECT r.name, SUM(p.amount) AS total_sales
FROM Payment p
JOIN Orders o ON p.order_id = o.order_id
JOIN Restaurant r ON r.restaurant_id = o.restaurant_id
GROUP BY r.name;

-- 6. LIST ALL ORDERS WITH CUSTOMER AND RESTAURANT NAME
SELECT o.order_id, c.name AS customer, r.name AS restaurant, o.status
FROM Orders o
JOIN Customer c ON o.customer_id = c.customer_id
JOIN Restaurant r ON o.restaurant_id = r.restaurant_id;

-- 7. FIND TOP PRICED MENU ITEMS
SELECT item_name, price
FROM Menu_Item
ORDER BY price DESC;

-- 8. CUSTOMERS WHO ORDERED FROM A RESTAURANT
SELECT name
FROM Customer
WHERE customer_id IN (
    SELECT customer_id
    FROM Orders
    WHERE restaurant_id = 1
);

-- 9. AVERAGE RESTAURANT RATING WITH >3 REVIEWS
SELECT r.name, AVG(rv.rating) AS avg_rating
FROM Review rv
JOIN Restaurant r ON rv.restaurant_id = r.restaurant_id
GROUP BY r.name
HAVING COUNT(rv.review_id) >= 3;

-- 10. UPDATE MENU ITEM PRICE
UPDATE Menu_Item
SET price = price + 10
WHERE item_id = 3;

-- 12. COUNT TOTAL NUMBER OF ORDERS PLACED
SELECT COUNT(*) AS total_orders
FROM Orders;
