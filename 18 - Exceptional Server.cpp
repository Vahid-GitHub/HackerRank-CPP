/* Enter your code here. */
        Server server;
        try {
            cout<<Server::compute(A,B)<<endl;
        }
        catch (bad_alloc& e) {
            cout << "Not enough memory" << endl;
        }
        //catch (invalid_argument& e) {
        //    cout << e.what() << endl;
        //}
        catch (exception& a) {
            cout << "Exception: " << a.what() << endl;
        }
        catch (...) {
            cout << "Other Exception" << endl;
        }
