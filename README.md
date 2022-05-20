# PHẠM MINH NGUYÊN - 21020084 - INT2215_1

## BÀI TẬP CUỐI KHÓA: PONG


### 1. HƯỚNG DẪN CÀI ĐẶT 
#### *(Lưu ý: File *pong.sh* dưới đây phải được chạy bằng phần mềm Git Bash)*
 * Bước 1: Đồng bộ code về máy của bạn, sử dụng lệnh:
      **git clone https://github.com/21020084/Pong.git**.
 * Bước 2: Vào đường link *https://drive.google.com/file/d/1fQiOEtSXu8Furb8clbEqDjzjwq2VJMIo/view?usp=sharing* tải file *.zip*, sau đó giải nén đến thư mục *pong* vừa được đồng bộ về máy.
 * Bước 2: Click chuột để chạy file *pong.sh* và đợi chương trình biên dịch xong.
 * Bước 3: Các lần tiếp theo chạy chương trình chỉ cần chạy file *pong.sh*.


### 2. Ý TƯỞNG VÀ MÔ TẢ CHUNG
* **Ý tưởng:**
  Lấy ý tương từ trò chơi Pong cổ diển.
* **Mô tả chung:**
  - Hai tấm ván được điều khiển di chuyển dọc theo hai bức tường đối diện nhau, trong một hộp kín là màn hình.
  - Nhiệm vụ của người chơi là ngăn quả bóng chạm vào bức tường phía mình. Nếu để bóng chạm tường, đối thủ của người chơi sẽ được cộng 1 điểm và lượt chơi đó sẽ kết thúc.
  - Có 2 chế độ chơi: chơi đơn và chơi hai người. Ở chế độ chơi đơn, tấm ván bên trái sẽ do máy tính điều khiển.


### 3. CÁC CHỨC NĂNG
#### *(Lưu ý: Chức năng của các nút bấm giống tên gọi của nó)*
* **Menu chính:**
  Gồm 3 nút bấm: *Chơi đơn*, *Chơi hai người* và *Thoát trò chơi*.
* **Menu tạm dừng:**
  - Gồm 2 nút bấm: *Tiếp tục* và *Về menu chính*.
  - Xuất hiện khi trò chơi đang tạm dừng giữa màn chơi.  
* **Màn chơi:**
  - Gồm 2 chế đọ: *Chơi đơn* và *Chơi hai người*.
  - Ở lượt chơi đầu tiên, người chơi bên phải phát bóng trước. Sau đó người thắng một lượt chơi sẽ được phát bóng ở lượt tiếp theo.
  - Góc phát bóng ở mỗi lượt chơi là ngẫu nhiên.
  - Tốc độ di chuyển của bóng tăng đều sau mỗi lượt chơi, tốc độ di chuyển của hai tấm ván tăng đều sau mỗi 5 lượt chơi. 
  - Sau 50 lượt chơi, bóng và hai tấm ván sẽ đạt tốc độ tối đa.
  - Có thể tạm dừng/tiếp tục màn chơi bằng cách nhấn ***Esc***, khi đó Menu tạm dừng sẽ xuất hiện.
* **Âm thanh: Gồm 3 loại**
  - Tiếng bóng chạm vào các tấm ván.
  - Tiếng bóng chạm vào cạnh trên hoặc dưới của màn hình.
  - Âm thanh kết thúc lượt chơi, bóng chạm vào cạnh trái hoặc phải của màn hình.

**Link video demo:** ***https://youtu.be/fvR1D5d5crM***.

### 4. CÁC KỸ THUẬT LẬP TRÌNH VÀ CẤU TRÚC DỮ LIỆU 
* **Kỹ thuật lập trình:**
  - Dùng con trỏ và tham chiếu.
  - Lập trình hướng đối tượng.
* **Các cấu trúc dữ liệu:**
  - *std::map*:  Dùng để lưu và quản lý các đối tượng (nút bấm, bóng, tấm ván,...) của trò chơi. 
  - *std::stack*:  Dùng để lưu và quản lý các trạng thái (chơi đơn, chơi hai người, tạm dừng,...) của trò chơi.
  - *std::shared_ptr*:  Dùng với mục đích giảm bớt tham số cần bởi những phương thức giống nhau của các đối tượng khác nhau.
### 5. TỔNG KẾT
* **Kết luận và hướng phát triển:**
  - Đây là một dự án đơn giản viết bằng ngôn ngữ C++ kết hợp thư viện SFML, sử dụng Lập trình hướng đối tượng.
  - Kỹ thuật Lập trình hướng đối tượng trong dự án này chỉ dùng lại ở mức cơ bản và còn nhiều sai sót.
  - Cấu trúc *std::shared_ptr* có thể chưa được sử dụng đúng với tính năng ưu việt của nó.
  - Một số thành phần có thể được thêm vào Game loop để làm trò chơi ổn định và mượt hơn.
  - Một số phương thức có thể được viết thành một lớp riêng, thay vì nằm trong các đối tượng như hiện tại. Mục đích cuối cùng là có thể phát triển dự án hiện tại thành các dự án lớn hơn một cách dễ dàng hơn.
* **Một số kinh nghiệm rút ra sau dự án:**
  - Bước đầu làm quen với cách tách và tổ chức file trong một dự án lập trình.
  - Biết cách làm việc với *Makefile* và *command line (Git Bash)* ở mức cơ bản. 
  - Làm quen với Lập trình hướng đối tượng, một kỹ thuật quan trọng và rất phổ biến trong lập trình chuyên nghiệp.
  - Làm quen với một thư viện đồ họa viết bằng C++, biết thêm một số kiến thức về Lập trình hướng đối tượng thông qua API của thư viện này.


#### Link tham khảo:
* https://gameprogrammingpatterns.com/game-loop.html
* http://blog.nuclex-games.com/tutorials/cxx/game-state-management/
* https://gameprogrammingpatterns.com/component.html
* https://medium.com/achiev/game-from-scratch-with-c-and-sfml-1-f17dcc2b6092
* https://github.com/SonarSystems/Flappy-Bird-SFML-Clone
