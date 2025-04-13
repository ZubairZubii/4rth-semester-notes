
package task2_mev_spring;
import org.springframework.beans.factory.annotation.Autowired;


public class task2 {
    private String title;
    private String artist;
    private double duration;

    public task2(String title, String artist, double duration) {
        this.title = title;
        this.artist = artist;
        this.duration = duration;
    }


    public String getTitle() {
        return title;
    }

    public String getArtist() {
        return artist;
    }

    public double getDuration() {
        return duration;
    }
}


 class Hamd extends task2 {
    public Hamd(String title, String artist, double duration) {
        super(title, artist, duration);
    }
}


 class Naat extends task2 {
    public Naat(String title, String artist, double duration) {
        super(title, artist, duration);
    }
}


 class MP3Player {


		    private task2 kalaam;
		    
		    @Autowired
		    public void setkalaam(task2 kalaam) {
		        this.kalaam = kalaam;
		    }

		    public void playKalaam() {
		        System.out.println("Playing " + kalaam.getTitle() + " by " + kalaam.getArtist() + 
		                " (" + kalaam.getDuration() + " seconds)");
		    }

		    
		
	}

