/*
- olist_products;
- olist_order_items;
- olist_orders;
- olist_order_payments;
- olist_product_category_name_translation;
*/

SELECT *
FROM JLEON.olist_products;

SELECT * 
FROM JLEON.olist_order_items;

SELECT * 
FROM JLEON.olist_orders;

SELECT *
FROM JLEON.olist_order_payments;

SELECT *
FROM JLEON.olist_product_category_name_translation;

--Punto 12

SELECT
    TO_NUMBER(TO_CHAR(OLR.order_purchase_timestamp, 'MM')) AS Month_no,
    TO_CHAR(OLR.order_purchase_timestamp, 'Mon') AS Month,
    ROUND(AVG(
        CASE
            WHEN TO_CHAR(OLR.order_purchase_timestamp, 'YYYY') = '2016' THEN (OLR.order_delivered_customer_date - OLR.order_purchase_timestamp)
            ELSE NULL
        END
    ), 0) AS Year2016_real_time,
    ROUND(AVG(
        CASE
            WHEN TO_CHAR(OLR.order_purchase_timestamp, 'YYYY') = '2017' THEN (OLR.order_delivered_customer_date - OLR.order_purchase_timestamp)
            ELSE NULL
        END
    ), 0) AS Year2017_real_time,
    ROUND(AVG(
        CASE
            WHEN TO_CHAR(OLR.order_purchase_timestamp, 'YYYY') = '2018' THEN (OLR.order_delivered_customer_date - OLR.order_purchase_timestamp)
            ELSE NULL
        END
    ), 0) AS Year2018_real_time,
    ROUND(AVG(
        CASE
            WHEN TO_CHAR(OLR.order_purchase_timestamp, 'YYYY') = '2016' THEN (OLR.order_estimated_delivery_date - OLR.order_purchase_timestamp)
            ELSE NULL
        END
    ), 0) AS Year2016_estimated_time,
    ROUND(AVG(
        CASE
            WHEN TO_CHAR(OLR.order_purchase_timestamp, 'YYYY') = '2017' THEN (OLR.order_estimated_delivery_date - OLR.order_purchase_timestamp)
            ELSE NULL
        END
    ), 0) AS Year2017_estimated_time,
    ROUND(AVG(
        CASE
            WHEN TO_CHAR(OLR.order_purchase_timestamp, 'YYYY') = '2018' THEN (OLR.order_estimated_delivery_date - OLR.order_purchase_timestamp)
            ELSE NULL
        END
    ), 0) AS Year2018_estimated_time
FROM JLEON.olist_orders OLR
WHERE OLR.order_status = 'delivered'
    AND OLR.order_delivered_customer_date IS NOT NULL
GROUP BY TO_NUMBER(TO_CHAR(OLR.order_purchase_timestamp, 'MM')), TO_CHAR(OLR.order_purchase_timestamp, 'Mon');


--Punto 13
SELECT *
FROM(
    SELECT tra.product_category_name_english , SUM(opp.payment_value)Ingresos, COUNT(OI.order_Id) Ordenes
    FROM 
        JLEON.olist_products PR
        INNER JOIN
        JLEON.olist_product_category_name_translation TRA
        ON tra.product_category_name = pr.product_category_name
        INNER JOIN
        JLEON.olist_order_items OI
        ON pr.product_id = oi.product_id
        INNER JOIN JLEON.olist_orders OLR
        ON oi.order_id = olr.order_id
        INNER JOIN JLEON.olist_order_payments OPP
        ON opp.order_id = olr.order_id
        WHERE olr.order_status != 'canceled' 
        and 
        olr.order_delivered_customer_date is not null
        GROUP BY tra.product_category_name_english
        order by Ingresos desc
        ) TOP10
        WHERE ROWNUM <= 10;
        
--Punto 14
SELECT TO_NUMBER(TO_CHAR(OLR.order_purchase_timestamp, 'MM')) Month_no,
    TO_CHAR(OLR.order_purchase_timestamp, 'Mon') Month,
    ROUND(
        SUM(
        CASE
        WHEN TO_CHAR(OLR.order_purchase_timestamp, 'YYYY') = '2016' THEN pp.payment_value
        ELSE 0
        END
            ),2)AS Ingresos_2016,
    ROUND(
        SUM(
        CASE
        WHEN TO_CHAR(OLR.order_purchase_timestamp, 'YYYY') = '2017' THEN pp.payment_value
        ELSE 0
        END
            ),2)AS Ingresos_2017,
    ROUND(
        SUM(
        CASE
        WHEN TO_CHAR(OLR.order_purchase_timestamp, 'YYYY') = '2018' THEN pp.payment_value
        ELSE 0
        END
            ),2)AS Ingresos_2018
FROM 
    JLEON.olist_order_payments PP
    INNER JOIN
    JLEON.olist_orders OLR
    ON pp.order_id = olr.order_id
    WHERE olr.order_status = 'delivered' 
    and olr.order_delivered_customer_date is not null   
    GROUP BY TO_NUMBER(TO_CHAR(OLR.order_purchase_timestamp, 'MM')),TO_CHAR(OLR.order_purchase_timestamp, 'Mon');
    

    
    





 



