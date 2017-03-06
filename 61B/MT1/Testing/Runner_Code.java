List<Method> L = getMethodsWithAnnotation(TestSort.class,      
                                            org.junit.Test);
int numTests = L.size();
int numPassed = 0;
for (Method m : L) {
    result r = m.execute();
    if (r.passed == true) { numPassed += 1; }
    if (r.passed == false) { System.out.println(r.message); }
}
System.out.println(numPassed + “/” + numTests + “ passed!”);

