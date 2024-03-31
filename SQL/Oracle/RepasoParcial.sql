SELECT LL.agente, cc.Id_pais, AVG(LL.tiempo) "promedio tiempo"
FROM LLAMADAS LL
    INNER JOIN  
    CLIENTES CC on cc.id = ll.cliente_id
GROUP BY ll.agente, cc.id_pais;

SELECT *
FROM(
    SELECT LL.id
        FROM LLAMADAS LL
        INNER JOIN  
        CLIENTES CC on cc.id = ll.cliente_id
        INNER JOIN 
        PASISES PP on pp.id = cc.id_pais
        WHERE pp.descrip = '“Estados unidos' AND TO_CHAR(LL.FECHA,'YYYY-MM') = '2023-01'
        order by ll.tiempo desc
    ) TopLlamadas
    WHERE ROWNUM <= 10;

SELECT *
FROM AGENTES AA
    WHERE
    (
        NOT EXIST
        (
            SELECT * 
            FROM LLAMADAS LL
            WHERE ll.agente_id = aa.id 
        )
    )
    OR EXIST(
        SELECT * 
            FROM LLAMADAS LL
            WHERE ll.tiempo < (SELECT AVG(tiempo) from LLAMADAS) AND ll.agente_id = aa.id 
    )
    
SELECT id 
FROM(
    SELECT cc.id, COUNT(ll.id) "llamadas"
    FROM CLIENTES CC
    INNER JOIN 
    LLAMADAS la on cc.id = la.cliente_id
    WHERE cc.id IN (
        SELECT ll.id_cliente
        FROM LLAMADAS LL
        GROUP BY ll.id_cliente
        HAVING COUNT(*) > 3
    ) AND cc.edad > (SELECT AVG(cc.edad) FROM CLIENTES CC)
    group by cc.id
    order by "llamadas" desc
)
WHERE ROWNUM <= 10
    