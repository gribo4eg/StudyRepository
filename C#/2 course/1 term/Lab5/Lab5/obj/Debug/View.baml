   M S B A M L   `   `   `  ����?  ;Lab5, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:Lab5Lab5  5          Lab5.MainWindow   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      #lab5clr-namespace:Lab5     5        � Title$  	Zoo Staff��5      $	��530��5      $	��355��5       � DataContext 5	         Lab5.ViewModel  5
   
   .��5      � .+�5   
   �� $	��497��5      $	��191��5      $��	10,41,0,0q�5      $
��Left=�5      $	��Top=�5      ��5      �� *	Watchmans+ �� View 5      �� 5      .P�5      �� $
��Name��6K    �� DisplayMemberBinding 6%   �� *Name+6K   �� 5      $��Surname��6N    6%   �� *	Surname+6N   �� 5      $	��Age��6J    6%   �� *Age+6J   �� 5      $��Weight��6M    6%   �� *Weight+6M   5      5      �� 5   
   $��10,285,10,10q�5      $��LeftToRight=�5       �� Orientation$ 
Horizontal=�5       .+�5!      �� Name:6   �� 5"      $��67��6   ��6!   ��  �� Path$ WatchmanNameToAdd� �� Mode$ OneWayToSource=��� 5#      
Surname:6"   �� 5$      $	��103��6   ��6"   �� $ WatchmanSurnameToAdd�$ OneWayToSource=��� 5%      Age:6   �� 5&      $��45��6   ��6!   �� $ WatchmanAgeToAdd�$ OneWayToSource=��� 5'      	Weight:6!   �� 5(      $��50��6   ��6!   �� $ WatchmanWeightToAdd�$ OneWayToSource=��� 5)      $
��Auto��5*      $��Add Watchman��5,      ��5+      �� *AddWatchmanCommand+5,      5-      �� 5.   
   $��	10,10,0,0q�5/      $
��Left=�50      $	��Top=�51      $��Watchmans List:��52      �� 53   
   $��
10,254,0,0q�54      $
��Left=�55      $	��Top=�56      $��Add new Watchman:��57      58      59      