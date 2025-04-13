<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="ISO-8859-1"%>
<%@ taglib uri="http://www.springframework.org/tags/form" prefix="form"%>    
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>    
<!DOCTYPE html>
<html>
<head>
    <title>Seminar Form</title>
</head>
<body>
    <h2>Seminar Form</h2>
    <form action="/spring_mvc/saveSeminar" method="post">
        <table>
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
                <td colspan="2"><input type="submit" value="Save"/></td>
            </tr>
        </table>
    </form>
</body>
</html>
