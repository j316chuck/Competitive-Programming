package Language;

public class JavaPair<X, Y> {
    public X first;
    public Y second;

    public JavaPair(X f, Y s){
        first = f;
        second = s;
    }
    void setFirst(X f) {
        first = f;
    }
    void setSecond(Y s) {
        second = s;
    }

    @Override
    public boolean equals(Object p1){ //can also do p1.first.equals() and p2.first.equals();
        if(p1 == this) return true;
        if(p1 == null) return false;
        if(p1.getClass() != this.getClass()) return false;
        JavaPair other = (JavaPair) p1;
        return other.first.equals(this.first) && other.second.equals(this.second);
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + (first == null ? 0 : first.hashCode());
        result = prime * result + (second == null ? 0 : second.hashCode());
        return result;
    }
}