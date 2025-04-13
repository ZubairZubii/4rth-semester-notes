<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
    <title>Edit Seminar Form</title>
</head>
<body>
    <h2>Edit Seminar Form</h2>
    <form action="/spring_mvc/editsave" method="post">
        <table>
            <tr>
                <td>ID :</td>
                <td><input type="text" name="id" value="${command.id}" readonly="readonly"/></td>
            </tr>
            <tr>
                <td>Title :</td>
                <td><input type="text" name="title" value="${command.title}"/></td>
            </tr>
            <tr>
                <td>Description :</td>
                <td><input type="text" name="description" value="${command.description}"/></td>
            </tr>
            <tr>
                <td>Speaker :</td>
                <td><input type="text" name="speaker" value="${command.speaker}"/></td>
            </tr>
            <tr>
                <td>Date :</td>
                <td><input type="text" name="date" value="${command.date}"/></td>
            </tr>
            <tr>
                <td colspan="2"><input type="submit" value="Edit & Save"/></td>
            </tr>
        </table>
    </form>
</body>
</html>
