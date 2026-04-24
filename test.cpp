/**
 * Enhanced Server Process: Implements a non-preemptive priority scheduler.
 * Urgent requests (priority 1) always jump ahead of ordinary requests (priority 0).
 */
void priority_display_server() {
    // Two separate FIFO queues to manage different priority levels.
    Queue urgent_queue;
    Queue ordinary_queue;

    bool display_busy = false;
    ProcessId current_user;
    Message msg;

    while (true) {
        // SYSTEM CALL: Blocks the server until any module sends a report.
        receive(ANY, &msg);

        if (msg.type == REQUEST) {
            if (!display_busy) {
                // If the screen is black, the first requester gets it immediately,
                // regardless of their priority level.
                display_busy = true;
                current_user = msg.sender;
                send(current_user, GRANT);
            } else {
                /* * If the display is busy, we sort the process into the
                 * appropriate "waiting room" based on the message parameter.
                 */
                if (msg.priority == 1) {
                    enqueue(urgent_queue, msg.sender);
                } else {
                    enqueue(ordinary_queue, msg.sender);
                }
            }
        }
        else if (msg.type == RELEASE && msg.sender == current_user) {
            /*
             * SELECTION LOGIC:
             * When the display is freed, we check the Urgent Queue first.
             * This ensures "Pan boiling over" shows before "Hallway temp".
             */
            if (!is_empty(urgent_queue)) {
                // Urgent processes are served in FIFO order among themselves.
                current_user = dequeue(urgent_queue);
                send(current_user, GRANT);
                // display_busy stays true because we handed off the lock.
            }
            else if (!is_empty(ordinary_queue)) {
                // Only if NO urgent messages are waiting do we serve ordinary ones.
                current_user = dequeue(ordinary_queue);
                send(current_user, GRANT);
            }
            else {
                // Absolutely no one is waiting.
                display_busy = false;
            }
        }
    }
}