package espe.edu.ec.q38.model;
import java.util.ArrayList;

/**
 *
 * @Alan Arias
 */
public class D extends A{

    private E[] e = new E[5];
    private ArrayList<F> f;

    public D(E[] e, ArrayList<F> f, ArrayList<A> as) {
        super(as);
        this.e = e;
        this.f = f;
    }
    /**
     * @return the e
     */
    public E[] getE() {
        return e;
    }

    /**
     * @param e the e to set
     */
    public void setE(E[] e) {
        this.e = e;
    }

    /**
     * @return the f
     */
    public ArrayList<F> getF() {
        return f;
    }

    /**
     * @param f the f to set
     */
    public void setF(ArrayList<F> f) {
        this.f = f;
    }
    
}
