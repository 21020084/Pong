# PHẠM MINH NGUYÊN - 21020084 - INT2215_1

## BÀI TẬP CUỐI KHÓA: PONG


### 1. HƯỚNG DẪN CÀI ĐẶT 
#### *(Lưu ý: Câu lệnh và file "pong.sh" dưới đây phải được chạy bằng phần mềm Git Bash)*
 * Bước 1: Đồng bộ code về máy của bạn, sử dụng lệnh:
      **git clone https://github.com/21020084/Pong.git**.
 * Bước 2: Click chuột để chạy file "pong.sh" và đợi chương trình biên dịch xong.
 * Bước 3: Các lần tiếp theo chạy chương trình chỉ cần chạy file "pong.sh".


### 2. Ý TƯỞNG VÀ MÔ TẢ CHUNG
* **Ý tưởng:**
  Lấy ý tương từ trò chơi Pong cổ diển.
* **Mô tả chung:**
  - Hai tấm ván được điều khiển di chuyển dọc theo hai bức tường đối diện nhau, trong một hộp kín là màn hình.
  - Nhiệm vụ của người chơi là ngăn quả bóng chạm vào bức tường phía mình. Nếu để bóng chạm tường, đối thủ của người chơi sẽ được cộng 1 điểm và lượt chơi đó sẽ kết thúc.
  - Có 2 chế độ chơi: chơi đơn và chơi hai người. Ở chế độ chơi đơn, một tấm ván sẽ do máy tính điều khiển.


### 3. CÁC CHỨC NĂNG
#### *(Lưu ý: Chức năng của các nút bấm giống tên gọi của nó)*
* **Menu chính:**
  Gồm 3 nút bấm: Chơi đơn, Chơi hai người và Thoát trò chơi.
* **Menu tạm dừng:**
  - Gồm 2 nút bấm: Tiếp tục và Về menu chính.
  - Xuất hiện khi trò chơi đang tạm dừng giữa màn chơi.  
* **Màn chơi:**
  - Gồm 2 chế đọ: Chơi đơn và Chơi hai người.
  - Ở lượt chơi đầu tiên, người chơi bên phải phát bóng trước. Sau đó người thắng một lượt chơi sẽ được phát bóng ở lượt tiếp theo.
  - Góc phát bóng ở mỗi lượt chơi là ngẫu nhiên.
  - Tốc độ di chuyển của bóng và hai tấm ván tăng dần, đều sau các lượt chơi.
  - Sau 50 lượt chơi, bóng và hai tấm ván sẽ đạt tốc độ tối đa.
  - Có thể tạm dừng/tiếp tục màn chơi bằng cách nhấn ***Esc***, khi đó Menu tạm dừng sẽ xuất hiện.
* **Âm thanh: Gồm 3 loại**
  - Tiếng bóng chạm vào các tấm ván.
  - Tiếng bóng chạm vào cạnh trên hoặc dưới của màn hình.
  - Âm thanh kết thúc lượt chơi, bóng chạm vào cạnh trái hoặc phải của màn hình.  

### 4. CÁC KỸ THUẬT LẬP TRÌNH VÀ CẤU TRÚC DỮ LIỆU 
* **Kỹ thuật lập trình:**
  - Dùng con trỏ và tham chiếu.
  - Lập trình hướng đối tượng.
* **Các cấu trúc dữ liệu:**
  - *std::map*:  Dùng để lưu và quản lý các đối tượng (nút bấm, bóng, tấm ván,...) của trò chơi. 
  - *std::stack*:  Dùng để lưu và quản lý các trạng thái (chơi đơn, chơi hai người, tạm dừng,...) của trò chơi.
  - *std::shared_ptr*:  Dùng với mục đích giảm bớt tham số cần bởi những phương thức giống nhau của các đối tượng khác nhau.
### 5. TỔNG KẾT
* **Kết luận:**
  - Đây là một dự án đơn giản viết bằng ngôn ngữ C++ kết hợp thư viện SFML, sử dụng Lập trình hướng đối tượng.
  - Kỹ thuật Lập trình hướng đối tượng trong dự án này chỉ dùng lại ở mức cơ bản, chỉ được dùng nhằm mục đích làm quen với các tính chát và cách tổ chức cơ bản của Lập trình hướng đối tượng. 
