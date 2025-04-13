<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
    <title>View Seminars</title>
</head>
<body>
    <h2>Seminar List</h2>
    <table border="1" width="80%">
        <tr>
            <th>ID</th>
            <th>Title</th>
            <th>Description</th>
            <th>Speaker</th>
            <th>Date</th>
            <th>Edit</th>
            <th>Delete</th>
        </tr>
        <c:forEach var="seminar" items="${list}">
            <tr>
                <td>${seminar.id}</td>
                <td>${seminar.title}</td>
                <td>${seminar.description}</td>
                <td>${seminar.speaker}</td>
                <td>${seminar.date}</td>
                <td><a href="/spring_mvc/editseminar/${seminar.id}">edit</a></td>
                <td><a href="/spring_mvc/deleteseminar/${seminar.id}">delete</a></td>
            </tr>
        </c:forEach>
    </table>
</body>
</html>
