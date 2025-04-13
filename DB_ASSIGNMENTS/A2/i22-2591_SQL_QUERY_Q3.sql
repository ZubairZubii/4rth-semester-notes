use online_shopping_site;

--Query 1
--1. Select all columns from the Products table.
select * from Product;

--Query2
select name_ , price from product;
--2. Select specific columns (name, price) from the Products table.

--Query3
--3. Select products with a price greater than 1000.
select name_,price from product where price > 1000;


--Query4
--. Select products with a stock level less than or equal to 50.
select name_,stock_level from product where stock_level <=50;

--Query5
--5. Select products sorted by price in descending order.
select * from product Order By price DESC;

--Query6
--6. Select products with a price between 1000 and 5000.
select name_,price from product where price BETWEEN 1000 AND 5000;

--Query7
--7. Select products with a name starting with 'P'.
select * from product where name_ LIKE 'P%';

--Query8
--8. Select products with a name containing 'Shoes'.
select * from product where name_ LIKE '%Shoes%';

--Query9
--9. Select products sorted by name in ascending order.
select * from product Order By name_ ASC;

--Query10
--10. Select distinct categories from the Products table.
select DISTINCT category_id FROM product;

--Query11
--11. Select products with a price less than or equal to 3000 and in category 2.
select * from product where price <= 3000 AND category_id = 2;

--Query12
--12. Select products with a stock level greater than or equal to 10 and less than or equal to
select name_,stock_level from product where stock_level >=10 AND stock_level <=20;

--Query13
--13. Select products with a name starting with 'M' and a price greater than 5000.
select * from product where name_ LIKE 'M%' AND price > 5000;

--Query14
--14. Select products with a description containing 'embroidered' and prices less than 3000.
select * from product where description LIKE '%embroidered%' AND price < 3000;

--Query15
--15. Select products sorted by stock level in descending order.
select *from product Order By stock_level DESC;

--Query16
-- Select products with a name not starting with 'L'.
select * from product where name_ NOT LIKE 'L%' ;

--Query17
-- Select products with a price greater than the average price.
select*, (select AVG(price)  from Product) AS AVG_PRICE from Product where price > (Select AVG(price) from Product);


--Query18
--18. Select products with a stock level less than the minimum stock level.
select *  from Product p
where p.stock_level  < ( SELECT MIN(stock_level) FROM Product );



--Query 19
--19. Select products with a category ID in a list (1, 3, 4).
select * from Product WHERE category_id in (1,3,4);


-- 20. Select products with a name ending with 'Suit'.
select * from Product where name_ LIKE '%Suit';

-- 21. Count the total number of products.
select COUNT(product_id)as no_of_prod from Product  ;

--22. Calculate the average price of products.
select AVG(price) AS AVG_PRICE  from Product 

--23. Find the maximum price among products.
select MAX(price) as max_price from Product;

-- 24. Find the minimum stock level among products.
select MIN(stock_level) as min_stock_level from Product;

--25. Sum up the total stock levels of all products.
select SUM(stock_level) as total_stock_level from Product;

--26. Calculate the average stock level of products.
select AVG(stock_level) as avg_stock_level from Product;

--27. Count the number of products in each category.
select category_id,COUNT(product_id) as no_of_prod from Product GROUP BY category_id;

--28. Calculate the total value of all products (price * stock_level).
select SUM(price*stock_level) as total_value from Product;

--29. Find the product with the highest price.
select product_id,price,name_  from Product where price = (select MAX(price) from Product);

--30. Calculate the total number of characters in all product names.
select SUM(LEN(name_)) AS total_products_character from Product;

--31. Find the average price of products in each category.
select category_id,AVG(price) as avg_price from Product GROUP BY category_id;

--32. Find the product with the lowest stock level.
select * from Product where stock_level = (select MIN(stock_level) from Product);

--33. Calculate the total number of products in stock (stock_level > 0).
select COUNT(product_id)as no_of_prod from Product where stock_level > 0  ;


--34. Calculate the total price of all products.
select SUM(price*stock_level) as total_value from Product;


--35. Find the category with the most products.

select COUNT(category_id) AS no_of_cat from Product GROUP BY category_id HAVING COUNT(category_id) = (select MAX(no_of_cat) FROM (select COUNT(category_id) AS no_of_cat from Product GROUP BY category_id) count_);


--36. Calculate the difference between the highest and lowest prices.
select MAX(price) - MIN(price) as price_diff from Product;

--37. Find the product with the highest stock level
select * from Product where stock_level = (select MAX(stock_level) from Product);

--38. Find the category with the highest average price.
select category_id,AVG(price) as avg_price from Product GROUP BY category_id HAVING AVG(price) =(select MAX(avg_price) from(select category_id,AVG(price) as avg_price  from Product GROUP BY category_id) categories);

--39. Calculate the total number of products with prices greater than 5000.
select COUNT(product_id) as no_of_prod_5000 from Product where price > 5000;


--40. Calculate the total value of products in each category (price * stock_level).
select category_id, SUM(price*stock_level) as  total_val_categ from Product GROUP BY category_id ;


--41. Calculate the total number of orders.
select COUNT(Order_id) AS no_of_order from Orders;


--42. Calculate the average order total.
select AVG(total) as total_avg from
(
select  ord.Order_id,SUM(ordt.quantity* p.price) as total from Orders ord JOIN Order_Items ordt on ord.Order_id = ordt.order_id JOIN Product p on ordt.product_id = p.product_id GROUP BY ord.Order_id
) totals;

--43. Find the customer who made the most orders.


select c.customer_id,c.first_name,c.last_name,COUNT(o.Order_id)as no_of_order 
from Customers c JOIN Orders o on c.customer_id = o.customer_id 
GROUP BY  c.customer_id,c.first_name,c.last_name 
HAVING  COUNT(o.Order_id) = (select max(no_of_ord) from (select COUNT(Order_id ) as no_of_ord from Orders   GROUP BY customer_id) count_order);

--44. Calculate the total number of reviews for each product.

select p.product_id,p.name_, COUNT(r.review_id) as no_of_reviews from Product p JOIN Reviews r on p.product_id = r.product_id GROUP BY r.review_id , p.product_id,p.name_;


--45. Calculate the total revenue generated from each category.


select c.name_,c.category_id ,SUM(p.price *  ot.quantity) as total_revenue from Categories c JOIN Product p on  c.category_id = p.category_id JOIN Order_Items ot on p.product_id = ot.product_id JOIN Orders o on ot.order_id = o.Order_id GROUP BY c.name_,c.category_id;

--46. Find the average price of products purchased by each customer.

select c.customer_id,c.first_name,c.last_name ,AVG(p.price * ot.quantity) as avg_price_prod from Customers c JOIN Orders o ON c.customer_id = o.customer_id  JOIN Order_Items ot on ot.order_id = o.Order_id JOIN Product p on p.product_id= ot.product_id GROUP BY c.customer_id,c.first_name,c.last_name ;

--47. Calculate the total value of products in each promotion.


select pr.promotion_id, pr.name_ ,p.name_ as product_name, SUM(p.price * ot.quantity) as total_value
from Promotions pr
JOIN Product_Promotions pp on pr.promotion_id = pp.promotion_id
JOIN Product p on pp.product_id = p.product_id
JOIN Order_Items ot ON p.product_id = ot.product_id
JOIN Orders o ON ot.order_id = o.Order_id
GROUP BY pr.promotion_id, pr.name_,p.name_;


--48. Count the total number of carts for each customer.

select c.customer_id, COUNT(ca.cart_id) as total_carts
from Customers c
LEFT JOIN Carts ca on c.customer_id = ca.customer_id
GROUP BY c.customer_id;


--49. Calculate the total number of items in each order.
select o.Order_id, COUNT(ot.product_id) as total_items
from Orders o
LEFT JOIN Order_Items ot on o.Order_id = ot.order_id
GROUP BY o.Order_id;



--50. Find the customer with the highest total spending.
select c.customer_id, c.first_name, c.last_name, SUM(p.price * oi.quantity) as total_spending
from Customers c
JOIN Orders o on c.customer_id = o.customer_id
JOIN Order_Items oi on o.Order_id = oi.order_id
JOIN Product p on oi.product_id = p.product_id
GROUP BY c.customer_id, c.first_name, c.last_name
HAVING SUM(p.price * oi.quantity) = (
    select MAX(total_spending)
    from (
        select SUM(p.price * oi.quantity) as total_spending
        from Customers cu
        JOIN Orders ord on cu.customer_id = ord.customer_id
        JOIN Order_Items oit on ord.Order_id = oit.order_id
        JOIN Product prod on oit.product_id = prod.product_id
        GROUP BY cu.customer_id
    ) as max_spend
);



--51. Calculate the total number of reviews written by each customer.

select c.customer_id,COUNT(r.review_id) as no_of_reviews from Reviews r JOIN Customers c on r.customer_id = c.customer_id GROUP BY c.customer_id;


--52. Calculate the average order total for each customer.

select c.customer_id,c.first_name,c.last_name,AVG(total) as total_avg from
Customers c
JOIN
(
select  ord.customer_id,ord.Order_id,SUM(ordt.quantity* p.price) as total from Orders ord JOIN Order_Items ordt on ord.Order_id = ordt.order_id JOIN Product p on ordt.product_id = p.product_id GROUP BY ord.Order_id ,  ord.customer_id
) as total_order on c.customer_id = total_order.customer_id GROUP BY c.customer_id,c.first_name,c.last_name ;


--53. Find the category with the highest average price of products.
select c.category_id,c.name_,AVG(p.price) as avg_price from Categories c JOIN Product p on c.category_id = p.category_id GROUP BY c.category_id,c.name_ HAVING AVG(p.price) = (select MAX(avg_price) from (select c.category_id,AVG(p.price) as avg_price from Categories c JOIN Product p on c.category_id = p.category_id GROUP BY c.category_id) avg_cat_price);  

--54. Count the total number of orders placed in each month.
select MONTH(order_date ) as order_month,YEAR(order_date ) as order_year,COUNT(Order_id) as total_order_month from Orders GROUP BY MONTH(order_date ),YEAR(order_date );

--55. Calculate the total revenue generated by each customer.

select 
    c.customer_id, 
    c.first_name, 
    c.last_name, 
    SUM(p.price * oi.quantity) as total_revenue
from Customers c
JOIN Orders o on c.customer_id = o.customer_id
JOIN Order_Items oi on o.Order_id = oi.order_id
JOIN Product p on oi.product_id = p.product_id
GROUP BY c.customer_id, c.first_name, c.last_name;


--56. Calculate the total number of reviews for each product category.
select ct.category_id,ct.name_,COUNT(r.review_id) as no_of_reviews from Categories ct LEFT JOIN Product P ON ct.category_id = p.category_id LEFT JOIN Reviews r on p.product_id = r.product_id GROUP BY ct.category_id,ct.name_;

--57. Find the product with the highest average rating.
select p.product_id,AVG(r.rating) as avg_rating from Product p  JOIN Reviews r on p.product_id = r.product_id GROUP BY p.product_id HAVING AVG(r.rating) = (SELECT MAX(avg_rating) from (select AVG(r.rating) as avg_rating from Product p  JOIN Reviews r on p.product_id = r.product_id ) avg_rate_prd) ; 


--58. Calculate the total number of orders per year.
select YEAR(order_date) as order_year,COUNT(Order_id) as no_of_orders from Orders GROUP BY  YEAR(order_date);

--59. Find the customer who made the highest single order.
select 
TOP 1 
    c.customer_id, 
    c.first_name, 
    c.last_name, 
	o.Order_id,
    SUM(p.price * oi.quantity) as order_total
from Customers c
JOIN Orders o on c.customer_id = o.customer_id
JOIN Order_Items oi on o.Order_id = oi.order_id
JOIN Product p on oi.product_id = p.product_id
GROUP BY c.customer_id, c.first_name, c.last_name,o.Order_id ORDER BY order_total DESC ;


--60. Calculate the total value of products purchased by each customer.
select 
    c.customer_id, 
    c.first_name, 
    c.last_name, 
    SUM(p.price * oi.quantity) as total_value_purchased
from Customers c
JOIN Orders o on c.customer_id = o.customer_id
JOIN Order_Items oi on o.Order_id = oi.order_id
JOIN Product p on oi.product_id = p.product_id
GROUP BY c.customer_id, c.first_name, c.last_name;


--61. Find the total number of products in each category.
select c.category_id,c.name_,COUNT(p.product_id) as no_of_prod from Categories c JOIN Product p  on c.category_id=p.category_id  GROUP BY c.category_id,c.name_;

--62. Find the average price of products in each category.
select c.category_id,c.name_,AVG(p.price) as avg_price from Categories c JOIN Product p  on c.category_id=p.category_id  GROUP BY c.category_id,c.name_;


--63. Find the category with the highest total value of products (price * stock_level).

select ct.category_id,ct.name_,SUM(p.price * p.stock_level) as total_value from Categories ct JOIN Product p on ct.category_id = p.category_id GROUP BY ct.category_id,ct.name_;

--64. Find the average stock level of products in categories with more than 10 products.
select ct.category_id,ct.name_,avg(p.stock_level) as avg_stock_level from Categories ct JOIN Product p on ct.category_id = p.category_id GROUP BY ct.category_id,ct.name_ HAVING COUNT(p.product_id)> 10 ;


--65. Find the total number of orders for each customer.
select c.customer_id,c.first_name,c.last_name,COUNT(Order_id) as no_of_order from Customers c JOIN Orders o on c.customer_id = o.customer_id GROUP BY c.customer_id,c.first_name,c.last_name;


--66. Find the average order value (total price of order) for each customer.

select 
    c.customer_id, 
    c.first_name, 
    c.last_name, 
	AVG(total_order_value) as avg_order_value
	from Customers c
	JOIN 
	(
select 
	o.customer_id,
    o.Order_id,
    SUM(p.price * oi.quantity) as  total_order_value
from Orders o
JOIN Order_Items oi on o.Order_id = oi.order_id
JOIN Product p on oi.product_id = p.product_id                    
GROUP BY   o.Order_id,o.customer_id) as total_value on c.customer_id  = total_value.customer_id GROUP BY  c.customer_id, 
    c.first_name, 
    c.last_name ;


--67. Find the total number of products in stock in each city where customers are located.
--select CAST(c.shipping_address AS VARCHAR(255))  AS city,SUM(p.stock_level ) as total_prod_stock from Customers c JOIN Orders o on c.customer_id = o.customer_id JOIN Order_Items oi on oi.order_id = o.Order_id JOIN Product p on p.product_id = oi.product_id GROUP BY  CAST(c.shipping_address AS VARCHAR(255));


--68. Find the customer(s) with the highest total order value.
select 
TOP 1
    c.customer_id, 
    c.first_name, 
    c.last_name, 
    SUM(p.price * oi.quantity) as total_value_purchased
from Customers c
JOIN Orders o on c.customer_id = o.customer_id
JOIN Order_Items oi on o.Order_id = oi.order_id
JOIN Product p on oi.product_id = p.product_id
GROUP BY c.customer_id, c.first_name, c.last_name
ORDER BY  total_value_purchased DESC;


--69. Find the category with the highest average price.
select TOP 1 c.category_id,c.name_,AVG(p.price) as avg_price from Categories c JOIN Product p  on c.category_id=p.category_id  GROUP BY c.category_id,c.name_ ORDER BY avg_price DESC ;


--70. Find the product with the highest rating.
select p.product_id,count(r.rating) as prod_rating from Product p  JOIN Reviews r on p.product_id = r.product_id GROUP BY p.product_id HAVING count(r.rating)= (select MAX(prod_rating) FROM (select p.product_id,count(r.rating) as prod_rating from Product p  JOIN Reviews r on p.product_id = r.product_id GROUP BY p.product_id ) AS prod_rate);

--71. Find the total number of products purchased by each customer.
select 
    c.customer_id, 
    c.first_name, 
    c.last_name, 
    count(p.product_id) as no_of_prod
from Customers c
JOIN Orders o on c.customer_id = o.customer_id
JOIN Order_Items oi on o.Order_id = oi.order_id
JOIN Product p on oi.product_id = p.product_id
GROUP BY c.customer_id, c.first_name, c.last_name;


--72. Find the average rating of products in each category.
select p.category_id,c.name_,AVG(r.rating) as avg_rating from Categories c left JOIN Product p on c.category_id = p.category_id JOIN Reviews r on p.product_id = r.product_id GROUP BY  p.category_id,c.name_;

--73. Find the category with the highest total number of products.
select  p.category_id, c.name_,COUNT(p.product_id) AS total_products FROM Product p JOIN Categories c ON p.category_id = c.category_id GROUP BY p.category_id, c.name_ HAVING  COUNT(p.product_id) = (select MAX(total_products) from (select  p.category_id,COUNT(p.product_id) AS total_products FROM Product p JOIN Categories c ON p.category_id = c.category_id GROUP BY p.category_id) total_products);


--74. Find the customer(s) who have placed orders with the highest total value.
select 
    c.customer_id,
    c.first_name,
    c.last_name,
    SUM(p.price * oi.quantity) as total_order_value
from Customers c
JOIN Orders o on c.customer_id = o.customer_id
JOIN Order_Items oi on o.Order_id = oi.order_id
JOIN Product p on oi.product_id = p.product_id
GROUP BY c.customer_id, c.first_name, c.last_name
HAVING  SUM(p.price * oi.quantity) = (
    select MAX(total_value)
    from (
        select 
            SUM(p.price * oi.quantity) as total_value
        from Orders o
        JOIN Order_Items oi on o.Order_id = oi.order_id
        JOIN Product p on oi.product_id = p.product_id
        GROUP BY o.customer_id
    ) as max_values
);


--75. Find the product(s) with the highest total number of orders.
select
    p.product_id,
    p.name_,
    COUNT(oi.order_id) as total_orders
from Product p
JOIN Order_Items oi on p.product_id = oi.product_id
GROUP BY p.product_id, p.name_
HAVING COUNT(oi.order_id)= (
    select MAX(total_orders_count)
    from (
        select 
            COUNT(oi.order_id) as total_orders_count
        from Order_Items oi
        GROUP BY oi.product_id
    ) AS order_no
)


--76. Find the category with the highest total order value.
select 
    p.category_id,
    c.name_ ,
    SUM(p.price * oi.quantity) as total_order_value
from Product p
JOIN Categories c on p.category_id = c.category_id
JOIN Order_Items oi on p.product_id = oi.product_id
GROUP BY p.category_id, c.name_
HAVING SUM(p.price * oi.quantity) = (
    select MAX(total_value)
    from (
        select 
            SUM(p.price * oi.quantity) as total_value
        from Order_Items oi
        JOIN Product p on oi.product_id = p.product_id
        GROUP BY p.category_id
    ) as max_values
);


--77. Find the customer(s) with the highest average order value.

select 
    c.customer_id,
    c.first_name,
    c.last_name,
    AVG(p.price * oi.quantity) as average_order_value
from Customers c
JOIN Orders o on c.customer_id = o.customer_id
JOIN Order_Items oi on o.Order_id = oi.order_id
JOIN Product p on oi.product_id = p.product_id
GROUP BY c.customer_id, c.first_name, c.last_name
HAVING AVG(p.price * oi.quantity) = (
    select MAX(average_value)
    from (
        select 
            AVG(p.price * oi.quantity) as average_value
        from Orders o
        JOIN Order_Items oi on o.Order_id = oi.order_id
        JOIN Product p on oi.product_id = p.product_id
        GROUP BY o.customer_id
    ) as avg_values
);


--78. Find the product(s) with the highest total order quantity.
select 
    p.product_id,
    p.name_,
    SUM(oi.quantity) as total_order_quantity
from Product p
JOIN Order_Items oi on p.product_id = oi.product_id
GROUP BY p.product_id, p.name_
HAVING  SUM(oi.quantity) = (
    select MAX(total_quantity)
     from (
        select
            SUM(oi.quantity) as total_quantity
        from Order_Items oi
        GROUP BY oi.product_id
    ) as order_quantity
);


--79. Find the customer(s) who have placed orders with the highest average quantity per order.
select
    c.customer_id,
    c.first_name,
    c.last_name,
    AVG(oi.quantity) AS average_quantity_per_order
from Customers c
JOIN Orders o on c.customer_id = o.customer_id
JOIN Order_Items oi on o.Order_id = oi.order_id
GROUP BY c.customer_id, c.first_name, c.last_name
HAVING  AVG(oi.quantity)  = (
    select MAX(average_quantity)
    from (
        select 
            AVG(oi.quantity) as average_quantity
        from Orders o
        JOIN Order_Items oi on o.Order_id = oi.order_id
        GROUP BY o.customer_id
    ) as avg_order_quantity
);





--80. Find the category with the highest average stock level.
select
    p.category_id,
    c.name_ ,
    AVG(p.stock_level) as average_stock_level
from Product p
JOIN Categories c on p.category_id = c.category_id
GROUP BY p.category_id, c.name_
HAVING AVG(p.stock_level) = (
    select MAX(average_level)
    from (
        select
            AVG(p.stock_level) as average_level
        FROM Product p
        GROUP BY p.category_id
    ) as avg_level
);
