import pandas as pd
import numpy as np

# Function to generate event data
def generate_event(seed):
    np.random.seed(seed)
    time_steps = range(1, 1001)

    # Your logic to generate event data based on parameters
    # Replace the following lines with your actual logic
    event_data = pd.DataFrame({
        'time': time_steps,
        'event_id': range(1, 1001),
        'event_type': np.random.choice(['arrival', 'departure'], size=len(time_steps)),
        'length_event_list': np.random.randint(0, 5, len(time_steps)),
        'length_queue': np.random.randint(0, 10, len(time_steps)),
        'in_service': np.random.randint(0, 2, len(time_steps)),
        'machine_status': np.random.choice(['working', 'idle'], size=len(time_steps))
    })
    return event_data

# Function to generate state data
def generate_state(seed):
    np.random.seed(seed)
    time_steps = range(1, 1001)

    # Your logic to generate state data based on parameters
    # Replace the following lines with your actual logic
    state_data = pd.DataFrame({
        'ID': range(1, 1001),
        'arrival_time': np.random.uniform(0, 100, len(time_steps)),
        'start_service_time': np.random.uniform(0, 100, len(time_steps)),
        'completion_time': np.random.uniform(0, 100, len(time_steps)),
        'interrupted': np.random.randint(0, 2, len(time_steps))
    })
    return state_data

# Test harness for 100 different seed values
seeds_test = range(1, 101)

for seed in seeds_test:
    event_data = generate_event(seed)
    state_data = generate_state(seed)

    # Save to event.csv and state.csv
    event_data.to_csv(f'event_seed_{seed}.csv', index=False)
    state_data.to_csv(f'state_seed_{seed}.csv', index=False)
