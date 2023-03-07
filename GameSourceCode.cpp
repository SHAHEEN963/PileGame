#include <bits/stdc++.h>

using namespace std ;
//  © Shaheen

int32_t main()
{

    cout << "The Game Rule :\n" ;
    cout << "There are two piles of ten rocks\n" ;
    cout << "In each turn, you may either take one rock from a single pile, or one rock from both piles.\n" ;
    cout << "The player that takes the last rock wins the game.\n" ;

    cout << "\n\n" ;

    cout << "If you press 1 : that's mean minus 1 from Right pile\n" ;
    cout << "If you press 2 : that's mean minus 1 from Left pile\n" ;
    cout << "If you press 3 : that's mean minus 1 from Both pile\n" ;

    cout << "\n\n" ;

    while ( true )
    {
        cout << "Press * to start the game \n" ;
        string s ;
        getline( cin, s ) ;

        if ( s != "*" )
        {
            cout << "\n" ;
            cout << "Good Luck - Shaheen :) \n\n" ;
            continue ;
        }

        cout << "\n" ;
        int cnt1 = 10, cnt2 = 10 ;

        cout << "The Play Start : \n" ;
        cout << "Right Pile : " << cnt1 << " " ;
        for ( int right=0 ; right<cnt1 ; right++ ) cout << "o" ;
        cout << "\n" ;

        cout << "Left Pile : " << cnt2 << " " ;
        for ( int left=0 ; left<cnt2 ; left++ ) cout << "o" ;
        cout << "\n\n"  ;

        srand ( ( unsigned ) time ( NULL ) ) ;

        int x = rand() % 2 ;

        if ( x )
        {
            cout << "--- Computer start the game --- \n" ;
            int y = rand() % 2 ;
            y ? cnt1 -- : cnt2 -- ;
        }
        else cout << "--- You start the game --- \n" ;

        cout << "\n" ;

        int ok = 1 ;
        while ( cnt1 > 0 || cnt2 > 0 )
        {
            cout << "Right Pile : " << cnt1 << " " ;
            for ( int right=0 ; right<cnt1 ; right++ ) cout << "o" ;
            cout << "\n" ;

            cout << "Left Pile : " << cnt2 << " " ;
            for ( int left=0 ; left<cnt2 ; left++ ) cout << "o" ;
            cout << "\n\n"  ;

            if ( ok )
            {
                cout << "It's your turn \n" ;
                string in ;
                getline( cin, in ) ;

                bool ret = 0 ;
                if ( in == "1" ) cnt1 ? cnt1 -- : ret = 1 ;
                else if ( in == "2" ) cnt2 ? cnt2 -- : ret = 1 ;
                else if ( in == "3" ) cnt1 && cnt2 ? cnt1 --, cnt2 -- : ret = 1 ;
                else ret = 1 ;
                if ( ret ) cout << "-- Error --\n\n", ok = 1 - ok ;
            }
            else
            {
                cout << "The computer play ...\n\n" ;
                this_thread::sleep_for( chrono::milliseconds ( 1000 ) ) ;

                if ( cnt2 % 2 == 0 && cnt1 % 2 == 0 )
                {
                    cnt1 >= cnt2 ? cnt1 -- : cnt2 -- ;
                }
                else
                {
                    if ( cnt1 & 1 ) cnt1 -- ;
                    if ( cnt2 & 1 ) cnt2 -- ;
                }
            }
            ok = 1 - ok ;
        }

        if ( ! cnt1 && ! cnt2 )
        {
            cout << cnt1 << " " << cnt2 << "\n" ;
            cout << ( ok ?  "You Lose\n" : "You Win\n" ) << "\n" ;
        }
        else cout << "Error\n\n" ;
    }
}
