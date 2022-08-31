import java.util.*;
import java.io.*;

interface area{
    void cal(int dim);

}

class square implements area{
    int r; 
    @Override 
    public void cal(int dim){
        r = dim*dim;
    }
}

public class CarFueling {
    public static void main(String[] args) {
       square s = new square(); 
       s.r = 0; 
       s.cal(5);
       System.out.println(s.r);

    }
}
