import java.time.Instant;
import java.util.*;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

public class Main {
   public static void main(String[] args) throws InterruptedException {
       Scanner sc = new Scanner(System.in);
       int tItem;
        tItem = sc.nextInt();
        int wLimit;
        wLimit = sc.nextInt();
       HashMap<Double, Integer> UnitpriceWeight = new HashMap<Double, Integer>();

    for (int i = 0; i < tItem; i++)
    {
        int price = sc.nextInt();
        int weight = sc.nextInt();
        double unitPrice = (double)price/weight;
        UnitpriceWeight.put(unitPrice, weight);
    }

       HashMap<Double, Integer> sortedUnitpriceWeight = hmDescSortByKey(UnitpriceWeight);

        double maxProfit = 0;
    while (wLimit > 0){
        for (Double iterator: sortedUnitpriceWeight.keySet()){
            if(wLimit >= sortedUnitpriceWeight.get(iterator)){
            wLimit = wLimit - sortedUnitpriceWeight.get(iterator);
            maxProfit = maxProfit + sortedUnitpriceWeight.get(iterator)*iterator;
            } else {
                maxProfit = maxProfit + wLimit*iterator;
                wLimit = 0;
            }
        }
    }
       System.out.println("Max profit = "+maxProfit);
    }

    public static HashMap<Double, Integer> hmDescSortByKey(HashMap<Double,Integer> hm)
    {
        HashMap<Double, Integer> temp = hm.entrySet().stream().sorted(HashMap.Entry.comparingByKey(Comparator.reverseOrder())).collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue,(e1, e2) -> e1, LinkedHashMap::new));
        return temp;
    }
}


