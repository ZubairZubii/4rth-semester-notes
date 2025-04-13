<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>JSP Page Elements</title>
    <style>
        body {
            font-family: Arial;
            padding: 10px;
            margin-left: 100px;
        }
        .container {
            max-width: 600px;
            margin: 0;
        }
        .result {
            background-color: lightgray;
            padding: 15px;
            border-radius: 5px;
            margin-top: 20px;
        }
    </style>
</head>
<body>

<div class="container">
    <h1>JSP Page Elements</h1>
    
    <% 
        int n1 = 10;
        int n2 = 20;
        int s = n1 + n2;
    %>
    <div class="result">
        <p>Sum of n1 and n2: <b><%= s %></b></p>
    </div>

    <%!
        double calculate_Average(int n1, int n2) {
            return (double) (n1 + n2) / 2;
        }
    %>
    <div class="result">
        <p>Average of n1 and n2: <b><%= calculate_Average(n1, n2) %></b></p>
    </div>
</div>

</body>
</html>
