
INSERT INTO Customers (customer_id, first_name, last_name, email, shipping_address, billing_address)
VALUES
(1, 'Zeshan', 'Khan', 'zeshan@example.com', 'House No 17-B, Street No 30, Sector F-7/1, Islamabad', 'House No 17-B, Street No 30, Sector F-7/1, Islamabad'),
(2, 'Ali', 'Ahmed', 'ali@example.com', 'House No 25-A, Street No 10, Sector G-6/2, Islamabad', 'House No 25-A, Street No 10, Sector G-6/2, Islamabad'),
(3, 'Sara', 'Ali', 'sara@example.com', 'House No 14-C, Street No 20, Sector E-11, Islamabad', 'House No 14-C, Street No 20, Sector E-11, Islamabad'),
(4, 'Amir', 'Khan', 'amir@example.com', 'House No 6-D, Street No 5, Sector G-8/1, Islamabad', 'House No 6-D, Street No 5, Sector G-8/1, Islamabad'),
(5, 'Fatima', 'Hussain', 'fatima@example.com', 'House No 33-B, Street No 15, Sector F-10/2, Islamabad', 'House No 33-B, Street No 15, Sector F-10/2, Islamabad'),
(6, 'Nadia', 'Raza', 'nadia@example.com', 'House No 8-A, Street No 12, Sector H-13, Islamabad', 'House No 8-A, Street No 12, Sector H-13, Islamabad'),
(7, 'Imran', 'Ali', 'imran@example.com', 'House No 20-C, Street No 25, Sector D-12/4, Islamabad', 'House No 20-C, Street No 25, Sector D-12/4, Islamabad'),
(8, 'Ayesha', 'Khan', 'ayesha@example.com', 'House No 11-B, Street No 7, Sector I-10/3, Islamabad', 'House No 11-B, Street No 7, Sector I-10/3, Islamabad'),
(9, 'Usman', 'Hussain', 'usman@example.com', 'House No 22-D, Street No 18, Sector G-9/1, Islamabad', 'House No 22-D, Street No 18, Sector G-9/1, Islamabad'),
(10, 'Maria', 'Ahmed', 'maria@example.com', 'House No 5-C, Street No 8, Sector H-11/3, Islamabad', 'House No 5-C, Street No 8, Sector H-11/3, Islamabad');


create Table Categories(
category_id int,
name_ varchar(25),
parent_cateogory_id int,

);

INSERT INTO Categories (category_id, name_, parent_cateogory_id)
VALUES
(1, 'Electronics', 0), 
(2, 'Clothing', 0),
(3, 'Books', 0),
(4, 'Smartphones', 1),
(5, 'Laptops', 1),
(6, 'T-Shirts', 2),
(7, 'Dresses', 2),
(8, 'Fiction', 3),
(9, 'Non-Fiction', 3),
(10, 'Self-Help', 3);


create Table Promotions(
promotion_id int,
name_ varchar(25),
description text,
start_date date,
end_date date,
discount_type varchar(25),
discount_value decimal

);

INSERT INTO Promotions (promotion_id, name_, description, start_date, end_date, discount_type, discount_value)
VALUES
(1, 'New Year Sale', 'Welcome the New Year with big discounts!', '2024-01-01', '2024-01-10', 'Percentage', 10),
(2, 'Summer Clearance', 'Huge discounts on summer items!', '2024-07-01', '2024-07-15', 'Percentage', 20),
(3, 'Back to School', 'Get ready for school with these great deals!', '2024-08-15', '2024-09-15', 'Fixed Amount', 15.00),
(4, 'Black Friday', 'Unbeatable discounts on Black Friday!', '2024-11-25', '2024-11-30', 'Percentage', 30),
(5, 'Holiday Specials', 'Special discounts for the holiday season!', '2024-12-01', '2024-12-25', 'Fixed Amount', 25.00),
(6, 'Spring Sale', 'Fresh deals just in time for Spring!', '2024-03-20', '2024-04-10', 'Percentage', 15),
(7, 'Clearance', 'Clearance sale on selected items!', '2024-02-15', '2024-02-28', 'Percentage', 25),
(8, 'Valentine''s Day', 'Special discounts for Valentine''s Day!', '2024-02-01', '2024-02-14', 'Fixed Amount', 10.00),
(9, 'Mother''s Day', 'Treat your mom with these amazing deals!', '2024-05-01', '2024-05-15', 'Percentage', 20),
(10, 'Father''s Day', 'Special discounts for Father''s Day!', '2024-06-01', '2024-06-15', 'Fixed Amount', 12.00);



create Table Product(
product_id int,
name_ varchar(25),
description text,
category_id int,
price decimal,
stock_level int

);

INSERT INTO Product (product_id, name_, description, category_id, price, stock_level)
VALUES
(1, 'Smartphone X', 'Latest smartphone with advanced features', 4, 999.99, 100),
(2, 'Laptop Pro', 'Powerful laptop for all your needs', 5, 1299.99, 50),
(3, 'Blue T-Shirt', 'Comfortable cotton t-shirt', 6, 19.99, 200),
(4, 'Black Dress', 'Elegant black dress for any occasion', 7, 49.99, 150),
(5, 'Bestseller Book', 'A captivating fiction novel', 8, 29.99, 75),
(6, 'Self-Help Guide', 'Guide to personal growth and success', 10, 14.99, 100),
(7, 'Wireless Headphones', 'High-quality headphones for immersive sound', 4, 79.99, 120),
(8, 'Gaming Laptop', 'Ultimate gaming experience on-the-go', 5, 1999.99, 30),
(9, 'Graphic T-Shirt', 'Stylish graphic t-shirt for casual wear', 6, 24.99, 180),
(10, 'Summer Dress', 'Light and breezy dress for summer days', 7, 39.99, 100);


create Table Carts(
cart_id int,
customer_id int,
creation_date date
);



INSERT INTO Carts (cart_id, customer_id, creation_date)
VALUES
(1, 1, '2024-03-19'),
(2, 2, '2024-03-19'),
(3, 3, '2024-03-19'),
(4, 4, '2024-03-19'),
(5, 5, '2024-03-19'),
(6, 6, '2024-03-19'),
(7, 7, '2024-03-19'),
(8, 8, '2024-03-19'),
(9, 9, '2024-03-19'),
(10, 10, '2024-03-19');




create Table Orders(
Order_id int,
customer_id int,
order_date date,
order_status varchar(25)
);

INSERT INTO Orders (order_id, customer_id, order_date, order_status)
VALUES
(1, 1, '2024-03-19', 'Pending'),
(2, 2, '2024-03-19', 'Processing'),
(3, 3, '2024-03-19', 'Shipped'),
(4, 4, '2024-03-19', 'Delivered'),
(5, 5, '2024-03-19', 'Cancelled'),
(6, 6, '2024-03-19', 'Pending'),
(7, 7, '2024-03-19', 'Processing'),
(8, 8, '2024-03-19', 'Shipped'),
(9, 9, '2024-03-19', 'Delivered'),
(10, 10, '2024-03-19', 'Cancelled');



create Table Product_Promotions(
product_promotion_id int,
product_id int,
promotion_id int
);


INSERT INTO Product_Promotions (product_promotion_id, product_id, promotion_id)
VALUES
(1, 1, 1),
(2, 2, 2),
(3, 3, 3),
(4, 4, 4),
(5, 5, 5),
(6, 6, 6),
(7, 7, 7),
(8, 8, 8),
(9, 9, 9),
(10, 10, 10);

create Table Reviews(
review_id int,
product_id int,
customer_id int,
rating int,
review_text text,
review_date date

);


INSERT INTO Reviews (review_id, product_id, customer_id, rating, review_text, review_date)
VALUES
(1, 1, 1, 5, 'Great phone, excellent features!', '2024-03-19'),
(2, 2, 2, 4, 'Very satisfied with the performance.', '2024-03-19'),
(3, 3, 3, 5, 'Comfortable and stylish.', '2024-03-19'),
(4, 4, 4, 4, 'Perfect fit, love the design.', '2024-03-19'),
(5, 5, 5, 5, 'Couldn''t put it down, highly recommended!', '2024-03-19'),
(6, 6, 6, 4, 'Helped me a lot, worth the read.', '2024-03-19'),
(7, 7, 7, 5, 'Amazing sound quality!', '2024-03-19'),
(8, 8, 8, 4, 'Runs all my favorite games smoothly.', '2024-03-19'),
(9, 9, 9, 5, 'Unique design, received many compliments.', '2024-03-19'),
(10, 10, 10, 4, 'Perfect for summer events.', '2024-03-19');

create Table Cart_Items(
cart_item_id int,
cart_id int,
product_id int,
quantity int
);

INSERT INTO Cart_Items (cart_item_id, cart_id, product_id, quantity)
VALUES
(1, 1, 1, 1),
(2, 2, 2, 2),
(3, 3, 3, 1),
(4, 4, 4, 1),
(5, 5, 5, 2),
(6, 6, 6, 1),
(7, 7, 7, 1),
(8, 8, 8, 1),
(9, 9, 9, 2),
(10, 10, 10, 1);


create Table Order_Items(
order_item_id int,
order_id int,
product_id int,
quantity int
);

INSERT INTO Order_Items (order_item_id, order_id, product_id, quantity)
VALUES
(1, 1, 1, 1),
(2, 2, 2, 2),
(3, 3, 3, 1),
(4, 4, 4, 1),
(5, 5, 5, 2),
(6, 6, 6, 1),
(7, 7, 7, 1),
(8, 8, 8, 1),
(9, 9, 9, 2),
(10, 10, 10, 1);








