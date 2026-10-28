class MedianFinder {
    // Max heap holding the smaller half of the elements (top = largest of that half).
    priority_queue<int> lowHalf;
    // Min heap holding the larger half of the elements (top = smallest of that half).
    priority_queue<int, vector<int>, greater<int>> highHalf;

public:
    MedianFinder() {}

    void addNum( int num ) {
        // Decide which heap the new element belongs to.
        if( lowHalf.empty() || num <= lowHalf.top() )
            lowHalf.push( num );
        else
            highHalf.push( num );

        // Rebalance so the heaps differ in size by at most one,
        // keeping lowHalf either equal in size to or one larger than highHalf.
        if( lowHalf.size() > highHalf.size() + 1 )
        {
            highHalf.push( lowHalf.top() );
            lowHalf.pop();
        }
        else if( highHalf.size() > lowHalf.size() )
        {
            lowHalf.push( highHalf.top() );
            highHalf.pop();
        }
    }

    double findMedian() {
        if( lowHalf.size() > highHalf.size() )
            return lowHalf.top();

        return ( lowHalf.top() + highHalf.top() ) / 2.0;
    }
};
