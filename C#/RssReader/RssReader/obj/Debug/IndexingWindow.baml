   M S B A M L   `   `   `  ����D  @RssReader, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null%clr-namespace:RssReader	RssReader  5   	       RssReader.IndexingWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   )localclr-namespace:RssReader     5   	     � 
ResizeMode$  NoResize=�5   	    � Title$ Search results��5	   	   $	��406��6    $	��664��6-   .��5
      � $��0,0,2,0q�6   .+�5   
   �� -   5        $��	newsItems��5      $
��Left=�6$   $	��353��6?   $��	10,10,0,0q�6L   $	��Top=�6_   $	��298��6w    �� View 5      �� 5      .P�5      �� $��Search Result��6%    �� Width$	 298��6<    �� DisplayMemberBinding 6H   ��  �� Path$ Title�5      5      �� 5   
   $��Title:��6   $��
313,10,0,0q�6!   $
��Left=�65   $	��Top=�6P   $��26��6h    J� RenderTransformOrigin$ 1,0.5&�6t   �� 5   
   $��Link:��6   $��
313,93,0,0q�6    $
��Left=�64   $	��Top=�6O   $��35��6g   �� 5   
   $��Description:��6   $��313,192,0,0q�6'   $
��Left=�6<   $	��Top=�6W   $ 0.521,2.154&�6o   �� 5   
    �� 
IsReadOnly . $
��Left=�5      $��47��6,   $��
313,41,0,0q�68    �� TextWrapping$
 Wrap=�6L   $	��Top=�6`   $	��327��6x   ��5      �� *SelectedItem.Title+	 �� ElementName$	 	newsItems��5   x   �� 5   
    . $
��Left=�5      $��63��6,   $��313,124,0,0q�68   $
 Wrap=�6M   $	��Top=�6a   $	��327��6y   ��5      �� *SelectedItem.Link+$	 	newsItems��5   y   �� 5   
    . $
��Left=�5      $��78��6,   $��313,223,0,0q�68   $
 Wrap=�6M   $	��Top=�6a   $	��327��6y   ��5      �� *SelectedItem.Description+$	 	newsItems��5   y   �� 5   
   $��Date:��6   $��313,306,0,0q�6    $
��Left=�65   $	��Top=�6P   $ 0.521,2.154&�6h   �� 5   
    . $
��Left=�5      $��26��6,   $��313,337,0,0q�68   $
 Wrap=�6M   $	��Top=�6a   $	��327��6y   ��5      �� *SelectedItem.Date+$	 	newsItems��5   y   5      5      