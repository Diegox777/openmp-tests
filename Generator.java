import java.util.*;
import java.math.*;

class Generator {
  public static void main(String... bla) {
    Random r = new Random();
    int n = 1000000;
    System.out.println(n);
    for (int i = 0; i < n; i++)
      System.out.print(r.nextInt(10000) + " "); 
  }
}