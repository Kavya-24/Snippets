
import 'package:flutter/material.dart';
import 'package:flutter_foldable_sidebar_demo/custom_sidebar_drawer.dart';
import 'package:foldable_sidebar/foldable_sidebar.dart';

class HomeScreen extends StatefulWidget {
  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  FSBStatus _fsbStatus;

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        appBar: AppBar(
          automaticallyImplyLeading: false,
          backgroundColor: Colors.red[400],
          title: Text("Flutter Foldable Sidebar Demo") ,
        ),
        body: FoldableSidebarBuilder(
          drawerBackgroundColor: Colors.cyan[100],
          drawer: CustomSidebarDrawer(drawerClose: (){
            setState(() {
              _fsbStatus = FSBStatus.FSB_CLOSE;
            });
          },
          ),
          screenContents: welcomeScreen(),
          status: _fsbStatus,
        ),
        floatingActionButton: FloatingActionButton(
            backgroundColor:Colors.red[400],
            child: Icon(Icons.menu,
              color: Colors.white,
            ),
            onPressed: () {
              setState(() {
                _fsbStatus = _fsbStatus == FSBStatus.FSB_OPEN ?
                FSBStatus.FSB_CLOSE : FSBStatus.FSB_OPEN;
              });
            }),
      ),
    );
  }


  Widget welcomeScreen() {
    return Container(
      color: Colors.black.withAlpha(50),
      child: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text("Welcome To Flutter Dev's",
              style: TextStyle(fontSize: 25,color: Colors.white),
            ),
            SizedBox(height: 5,),
            Text("Click on FAB to Open Foldable Sidebar Drawer",
              style: TextStyle(fontSize: 18,color: Colors.white
              ),
            ),
          ],
        ),
      ),
    );
  }
}
