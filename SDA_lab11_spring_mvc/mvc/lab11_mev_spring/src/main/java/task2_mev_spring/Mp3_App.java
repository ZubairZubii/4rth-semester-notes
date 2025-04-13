package task2_mev_spring;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Mp3_App {


    public static void main(String[] args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("task2_beans.xml");

        MP3Player main =(MP3Player) context.getBean("mp3Player");
        main.playKalaam();;
    }


}